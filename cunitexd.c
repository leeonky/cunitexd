#include <stdlib.h>
#include <stdarg.h>
#include "cunitexd.h"

app_context actxt;

void init_app_context(app_context *context, const char *input, char *arg1, ...) {
	bzero(context, sizeof(app_context));

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
}

char* output_buffer(app_context *context) {
	fflush(context->output_stream);
	return context->output_buffer;
}

char* error_buffer(app_context *context) {
	fflush(context->error_stream);
	return context->error_buffer;
}

void close_app_context(app_context *context) {
	fclose(context->input_stream);
	fclose(context->output_stream);
	fclose(context->error_stream);
}

int invoke_app(app_context *ctxt, int(*sub_main)(int, char**, FILE *, FILE *, FILE *)){
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
		exit(CU_get_error());
	}
	return suite;
}

void add_case_with_name(CU_pSuite suite, const char *case_name, void (*test)()) {
	if (NULL == CU_add_test(suite, case_name, test)) {
		CU_cleanup_registry();
		exit(CU_get_error());
	}
}

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
