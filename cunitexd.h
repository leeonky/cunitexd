#ifndef CUNITEXD_H
#define CUNITEXD_H

#include <CUnit/Basic.h>
#include <stdio.h>

typedef struct app_context {
	char input_buffer[1024];
	char output_buffer[1024];
	char error_buffer[1024];
	FILE *input_stream;
	FILE *output_stream;
	FILE *error_stream;
	int argc;
	char *argv[64];
} app_context;

extern int init_app_context(app_context *, const char *, char *, ...);
extern char* output_buffer(app_context *);
extern char* error_buffer(app_context *);
extern int close_app_context(app_context *);
extern int invoke_app(app_context *, int(*)(int, char**, FILE *, FILE *, FILE *));

extern app_context actxt;

#define init_subject(input, ...) init_app_context(&actxt, input, ##__VA_ARGS__, "")
#define std_out output_buffer(&actxt)
#define std_err error_buffer(&actxt)
#define close_subject() close_app_context(&actxt)
#define invoke_subject(main_func) invoke_app(&actxt, main_func)

typedef int (*hook_pointer)();

typedef struct test_context {
	CU_pSuite suite;
	hook_pointer *init_pointer;
	hook_pointer *clear_pointer;
	hook_pointer before_each;
	hook_pointer after_each;
	void *subject;
} test_context;

extern void init_test();
extern int run_test();
extern CU_pSuite create_suite(const char *, int (*)(), int (*)());
extern void add_case_with_name(test_context *, const char *, void (*)());

#define add_case(suite, test_case) add_case_with_name(suite, #test_case, test_case)

#define MG_ID(prefix, id) MG_ID_I(prefix, id)
#define MG_ID_I(prefix, id) prefix ## id

#define ID_INC(id) ID_INC_I(id)
#define ID_INC_I(id) ID_INC_ ## id

#define ID_INC_0 1
#define ID_INC_1 2
#define ID_INC_2 3
#define ID_INC_3 4
#define ID_INC_4 5
#define ID_INC_5 6
#define ID_INC_6 7
#define ID_INC_7 8

#define ID_DEC(id) ID_DEC_I(id)
#define ID_DEC_I(id) ID_DEC_ ## id

#define ID_DEC_8 7
#define ID_DEC_7 6
#define ID_DEC_6 5
#define ID_DEC_5 4
#define ID_DEC_4 3
#define ID_DEC_3 2
#define ID_DEC_2 1
#define ID_DEC_1 0

#define CU_SYM(name1, name2) MG_ID(ctexd_, MG_ID(name1, name2))

#define SUITE_START_I(suit_name, index) \
	static hook_pointer CU_SYM(bfall_, index);\
	static hook_pointer CU_SYM(afall_, index);\
	static int CU_SYM(init_suit_, index)(){\
		if (CU_SYM(bfall_, index))\
			return CU_SYM(bfall_, index)();\
		return 0;\
	}\
	static int CU_SYM(clear_suit_, index)(){\
		if (CU_SYM(afall_, index))\
			return CU_SYM(afall_, index)();\
		return 0;\
	}\
	static test_context *CU_SYM(ctrl_, index)(){\
		static test_context tctxt;\
		tctxt.suite = create_suite(suit_name, CU_SYM(init_suit_, index), CU_SYM(clear_suit_, index));\
		tctxt.init_pointer = &CU_SYM(bfall_, index);\
		tctxt.clear_pointer = &CU_SYM(afall_, index);\
		return &tctxt;\
	}
#define SUITE_START(suit_name) SUITE_START_I(suit_name, __COUNTER__);

extern void *test_subject;

#define SUITE_CASE_I(case_name, index) \
	static hook_pointer CU_SYM(bf_, index);\
	static hook_pointer CU_SYM(af_, index);\
	static void *CU_SYM(sb_, index);\
	static void CU_SYM(case_i_, index)();\
	static void CU_SYM(case_, index)(){\
		test_subject = CU_SYM(sb_, index); \
		if(CU_SYM(bf_, index))\
			if(CU_SYM(bf_, index)())\
				fprintf(stderr, "\nBefore case got error");\
		CU_SYM(case_i_, index)();\
		if(CU_SYM(af_, index))\
			if(CU_SYM(af_, index)())\
				fprintf(stderr, "\nAfter case got error");\
		test_subject = NULL; \
	}\
	static test_context *CU_SYM(ctrl_, index)(){\
		test_context *ctxt = CU_SYM(ctrl_, ID_DEC(index))();\
		add_case_with_name(ctxt, case_name, CU_SYM(case_, index));\
		CU_SYM(bf_, index) = ctxt->before_each;\
		CU_SYM(af_, index) = ctxt->after_each;\
		CU_SYM(sb_, index) = ctxt->subject;\
		return ctxt;\
	}\
	static void CU_SYM(case_i_, index)()
#define SUITE_CASE(case_name) SUITE_CASE_I(case_name, __COUNTER__)

#define SUITE_END(suite_identity) \
void MG_ID(regist_, suite_identity)() {\
	CU_SYM(ctrl_, ID_DEC(__COUNTER__))();\
}

#define PROC_ALL(ba, index) \
	static int CU_SYM(ba, index)();\
	static test_context *CU_SYM(ctrl_, index)(){\
		test_context *ctxt = CU_SYM(ctrl_, ID_DEC(index))();\
		*(ctxt->MG_ID(ba, pointer)) = CU_SYM(ba, index);\
		return ctxt;\
	}\
	static int CU_SYM(ba, index)()
#define BEFORE_ALL() PROC_ALL(init_, __COUNTER__)
#define AFTER_ALL() PROC_ALL(clear_, __COUNTER__)

#define PROC_EACH(ba, index) \
	static int CU_SYM(ba, index)();\
	static test_context *CU_SYM(ctrl_, index)(){\
		test_context *ctxt = CU_SYM(ctrl_, ID_DEC(index))();\
		ctxt->MG_ID(ba, each) = CU_SYM(ba, index);\
		return ctxt;\
	}\
	static int CU_SYM(ba, index)()
#define BEFORE_EACH() PROC_EACH(before_, __COUNTER__)
#define AFTER_EACH() PROC_EACH(after_, __COUNTER__)

#define PROC_SUBJECT(t, index) \
	static t CU_SYM(subject_, index)();\
	static test_context *CU_SYM(ctrl_, index)(){\
		test_context *ctxt = CU_SYM(ctrl_, ID_DEC(index))();\
		ctxt->subject = CU_SYM(subject_, index);\
		return ctxt;\
	}\
	static t CU_SYM(subject_, index)()
#define SUBJECT(t) PROC_SUBJECT(t, __COUNTER__)

#define ADD_SUITE(suite_identity) do {\
		void MG_ID(regist_, suite_identity)();\
		MG_ID(regist_, suite_identity)();\
	} while(0)

extern const char *cunit_exd_string_equal(const char *, const char *);
extern const char *cunit_exd_ptr_equal(const void *, const void *);
extern int cunit_exd_equal(long long, long long, const char *, int, const char *);

#define CUE_ASSERT_BUF_LEN 1024

#define CUE_ASSERT_STRING_EQUAL(actual, expected) \
	{ CU_assertImplementation(!(strcmp((const char*)(actual), (const char*)(expected))), __LINE__, cunit_exd_string_equal(actual, expected), __FILE__, "", CU_FALSE); }

#define CUE_ASSERT_PTR_EQUAL(actual, expected) \
	do{\
		char buffer[CUE_ASSERT_BUF_LEN];\
		snprintf(buffer, sizeof(buffer), "Unexpect pointer\n\texpect: %p\n\tactual: %p", expected, actual);\
		CU_assertImplementation((void*)actual == (void*)expected, __LINE__, buffer, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_SUBJECT_SUCCEEDED() \
	do{\
		char buffer[CUE_ASSERT_BUF_LEN];\
		int code = ((int(*)())test_subject)();\
		snprintf(buffer, sizeof(buffer), "Expect called succeeded\n\tBut return(%d)", code);\
		CU_assertImplementation(0==code, __LINE__, buffer, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_SUBJECT_FAILED_WITH(err) \
	do{\
		char buffer[CUE_ASSERT_BUF_LEN];\
		int code = ((int(*)())test_subject)();\
		snprintf(buffer, sizeof(buffer), "Expect called failed with(%d)\n\tBut return(%d)", err, code);\
		CU_assertImplementation(err==code, __LINE__, buffer, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_STDOUT_EQ(out) \
	do{\
		char buffer[CUE_ASSERT_BUF_LEN];\
		const char *sout = std_out;\
		snprintf(buffer, sizeof(buffer), "Unexpect stdout\n\texpect: [%s]\n\tactual: [%s]", out, sout);\
		CU_assertImplementation(0==strcmp(sout, out), __LINE__, buffer, __FILE__, "", CU_FALSE);\
	} while(0)

#define extern_mock_void_function_0(func) \
	extern int func ## _times;\
	extern void (*mock_ ## func)();
#define mock_void_function_0(func) \
	int func ## _times;\
	void (*mock_ ## func)();\
	void func() {\
		++func ## _times;\
		if(mock_ ## func)\
			mock_ ## func();\
	}

#define extern_mock_void_function_1(func, t1) \
	extern int func ## _times;\
	extern void (*mock_ ## func)(t1);\
	extern t1 func ## _p1;
#define mock_void_function_1(func, t1) \
	int func ## _times;\
	t1 func ## _p1;\
	void (*mock_ ## func)(t1);\
	void func(t1 p1) {\
		++func ## _times;\
		func ## _p1 = p1;\
		if(mock_ ## func)\
			mock_ ## func(p1);\
	}

#define extern_mock_function_2(rtype, func, t1, t2) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)(t1, t2);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;
#define mock_function_2(rtype, func, t1, t2) \
	int func ## _times;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	rtype (*mock_ ## func)(t1, t2);\
	rtype func(t1 p1, t2 p2) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2);\
		return default_result;\
	}

#define extern_mock_function_4(rtype, func, t1, t2, t3, t4) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;
#define mock_function_4(rtype, func, t1, t2, t3, t4) \
	int func ## _times;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	rtype (*mock_ ## func)(t1, t2, t3, t4);\
	rtype func(t1 p1, t2 p2, t3 p3, t4 p4) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3, p4);\
		return default_result;\
	}

#define called_times_of(func) (func ## _times)

#define params_of(func, at) (func ## _p ## at)

#define init_mock_function(func, stub) \
	func ## _times = 0;\
	mock_ ## func = stub;

#define CU_EXPECT_CALLED_ONCE(func) CU_ASSERT_EQUAL(called_times_of(func), 1)
#define CU_EXPECT_CALLED_WITH_STRING(func, at, arg) CU_ASSERT_STRING_EQUAL(params_of(func, at), arg)
#define CU_EXPECT_CALLED_WITH(func, at, arg) CU_ASSERT_EQUAL(params_of(func, at), arg)

#endif
