#include <stdlib.h>
#include <stdarg.h>
#include "cunitexd.h"

FILE *fmemopen(void *, size_t, const char *);

test_app_context actxt;

int init_test_app_context(test_app_context *context, const char *input, char *arg1, ...) {
	close_test_app_context(context);

	va_list list;
	context->argc = 0;
	context->argv[context->argc++] = "main";
	va_start(list, arg1);
	while(strlen(arg1)>0) {
		context->argv[context->argc++] = arg1;
		arg1 = va_arg(list, char *);
	}
	va_end(list);

	strncpy(context->input_buffer, input, sizeof(context->input_buffer));
	context->input_stream = fmemopen(context->input_buffer, sizeof(context->input_buffer), "r");
	context->output_stream = fmemopen(context->output_buffer, sizeof(context->output_buffer), "w");
	context->error_stream = fmemopen(context->error_buffer, sizeof(context->error_buffer), "w");
	return !(context->input_stream && context->output_stream && context->error_stream);
}

char* output_buffer(test_app_context *context) {
	fflush(context->output_stream);
	return context->output_buffer;
}

char* error_buffer(test_app_context *context) {
	fflush(context->error_stream);
	return context->error_buffer;
}

int close_test_app_context(test_app_context *context) {
	if (context->input_stream) {
		int res1 = fclose(context->input_stream);
		int res2 = fclose(context->output_stream);
		int res3 = fclose(context->error_stream);

		bzero(context, sizeof(test_app_context));
		return res1 || res2 || res3;
	} else
		return 0;
}

int invoke_app(test_app_context *ctxt, int(*sub_main)(int, char**, FILE *, FILE *, FILE *)){
	return sub_main(ctxt->argc, ctxt->argv, ctxt->input_stream, ctxt->output_stream, ctxt->error_stream);
}

void init_test() {
	if (CUE_SUCCESS != CU_initialize_registry())
		exit(CU_get_error());
}

int run_test() {
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();
	return CU_get_error();
}

CU_pSuite create_suite(const char *suit_name, int (*init)(), int (*clean)()) {
	CU_pSuite suite = CU_add_suite(suit_name, init, clean);
	if (NULL == suite) {
		CU_cleanup_registry();
		fprintf(stderr, "Failed to create suite\n");
		exit(CU_get_error());
	}
	return suite;
}

void add_case_with_name(test_context *tctxt, const char *case_name, void (*test)()) {
	if (NULL == CU_add_test(tctxt->suite, case_name, test)) {
		CU_cleanup_registry();
		fprintf(stderr, "Failed to add case\n");
		exit(CU_get_error());
	}
}

void *test_subject;

const char *cunit_exd_string_equal(const char *actual, const char *expected) {
	static char buffer[1024];
	sprintf(buffer, "\nexpect: [%s]\nactual: [%s]", expected, actual);
	return buffer;
}

const char *cunit_exd_ptr_equal(const void *actual, const void *expected) {
	static char buffer[256];
	sprintf(buffer, "\nexpect: %p\nactual: %p", expected, actual);
	return buffer;
}

int cunit_exd_equal(long long actual, long long expected, const char *file, int line, const char *func) {
	static char buffer[256];
	sprintf(buffer, "\nexpect: %lld\nactual: %lld", expected, actual);
	return CU_assertImplementation(((actual) == (expected)), line, buffer, file, func, CU_FALSE);
}
