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

extern void init_app_context(app_context *, const char *, char *, ...);
extern char* output_buffer(app_context *);
extern char* error_buffer(app_context *);
extern void close_app_context(app_context *);
extern int invoke_app(app_context *, int(*)(int, char**, FILE *, FILE *, FILE *));

extern app_context actxt;

#define init_subject(input, ...) init_app_context(&actxt, input, ##__VA_ARGS__, "")
#define std_out output_buffer(&actxt)
#define std_err error_buffer(&actxt)
#define close_subject() close_app_context(&actxt)
#define invoke_subject(main_func) invoke_app(&actxt, main_func)

extern void init_test();
extern int run_test();
extern CU_pSuite create_suite(const char *, int (*)(), int (*)());
extern void add_case_with_name(CU_pSuite, const char *, void (*)());

#define add_case(suite, test_case) add_case_with_name(suite, #test_case, test_case)

#define MERGE_IDENTITY(prefix, id) MERGE_IDENTITY_I(prefix, id)
#define MERGE_IDENTITY_I(prefix, id) prefix ## id

#define ID_INC(id) ID_INC_I(id)
#define ID_INC_I(id) ID_INC_ ## id

#define ID_INC_0 1
#define ID_INC_1 2
#define ID_INC_2 3
#define ID_INC_3 4

#define ID_DEC(id) ID_DEC_I(id)
#define ID_DEC_I(id) ID_DEC_ ## id

#define ID_DEC_4 3
#define ID_DEC_3 2
#define ID_DEC_2 1
#define ID_DEC_1 0

#define CASE_PREFIX cunitexd_case

#define SUITE_START(suit_name) \
	static CU_pSuite MERGE_IDENTITY(MERGE_IDENTITY(CASE_PREFIX, _ctrl_), __COUNTER__)(){ return create_suite(suit_name, NULL, NULL); }

#define SUITE_CASE_I(case_name, index) \
	static void MERGE_IDENTITY(CASE_PREFIX, index)();\
	static CU_pSuite MERGE_IDENTITY(MERGE_IDENTITY(CASE_PREFIX, _ctrl_), index)(){\
		CU_pSuite ctxt = MERGE_IDENTITY(MERGE_IDENTITY(CASE_PREFIX, _ctrl_), ID_DEC(index))();\
		add_case_with_name(ctxt, case_name, MERGE_IDENTITY(CASE_PREFIX, index));\
		return ctxt;\
	}\
	static void MERGE_IDENTITY(CASE_PREFIX, index)()

#define SUITE_CASE(case_name) SUITE_CASE_I(case_name, __COUNTER__)

#define SUITE_END(suite_identity) \
void MERGE_IDENTITY(regist_, suite_identity)() {\
	MERGE_IDENTITY(MERGE_IDENTITY(CASE_PREFIX, _ctrl_), ID_DEC(__COUNTER__))();\
}

#define ADD_SUITE(suite_identity) MERGE_IDENTITY(regist_, suite_identity)()

extern const char *cunit_exd_string_equal(const char *, const char *);
extern const char *cunit_exd_ptr_equal(const void *, const void *);
extern int cunit_exd_equal(long long, long long, const char *, int, const char *);

#undef CU_ASSERT_EQUAL
#define CU_ASSERT_EQUAL(actual, expected) \
	cunit_exd_equal(actual, expected, __FILE__, __LINE__, "")

#undef CU_ASSERT_STRING_EQUAL
#define CU_ASSERT_STRING_EQUAL(actual, expected) \
	  { CU_assertImplementation(!(strcmp((const char*)(actual), (const char*)(expected))), __LINE__, cunit_exd_string_equal(actual, expected), __FILE__, "", CU_FALSE); }

#undef CU_ASSERT_PTR_EQUAL
#define CU_ASSERT_PTR_EQUAL(actual, expected) \
	  { CU_assertImplementation(((void*)(actual) == (void*)(expected)), __LINE__, cunit_exd_ptr_equal(actual, expected), __FILE__, "", CU_FALSE); }


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
