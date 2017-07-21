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
#define ID_INC_8 9
#define ID_INC_9 10
#define ID_INC_10 11
#define ID_INC_11 12
#define ID_INC_12 13
#define ID_INC_13 14
#define ID_INC_14 15
#define ID_INC_15 16
#define ID_INC_16 17
#define ID_INC_17 18
#define ID_INC_18 19
#define ID_INC_19 20
#define ID_INC_20 21
#define ID_INC_21 22
#define ID_INC_22 23
#define ID_INC_23 24
#define ID_INC_24 25
#define ID_INC_25 26
#define ID_INC_26 27
#define ID_INC_27 28
#define ID_INC_28 29
#define ID_INC_29 30
#define ID_INC_30 31
#define ID_INC_31 32
#define ID_INC_32 33
#define ID_INC_33 34
#define ID_INC_34 35
#define ID_INC_35 36
#define ID_INC_36 37
#define ID_INC_37 38
#define ID_INC_38 39
#define ID_INC_39 40
#define ID_INC_40 41
#define ID_INC_41 42
#define ID_INC_42 43
#define ID_INC_43 44
#define ID_INC_44 45
#define ID_INC_45 46
#define ID_INC_46 47
#define ID_INC_47 48
#define ID_INC_48 49
#define ID_INC_49 50

#define ID_DEC(id) ID_DEC_I(id)
#define ID_DEC_I(id) ID_DEC_ ## id

#define ID_DEC_50 49
#define ID_DEC_49 48
#define ID_DEC_48 47
#define ID_DEC_47 46
#define ID_DEC_46 45
#define ID_DEC_45 44
#define ID_DEC_44 43
#define ID_DEC_43 42
#define ID_DEC_42 41
#define ID_DEC_41 40
#define ID_DEC_40 39
#define ID_DEC_39 38
#define ID_DEC_38 37
#define ID_DEC_37 36
#define ID_DEC_36 35
#define ID_DEC_35 34
#define ID_DEC_34 33
#define ID_DEC_33 32
#define ID_DEC_32 31
#define ID_DEC_31 30
#define ID_DEC_30 29
#define ID_DEC_29 28
#define ID_DEC_28 27
#define ID_DEC_27 26
#define ID_DEC_26 25
#define ID_DEC_25 24
#define ID_DEC_24 23
#define ID_DEC_23 22
#define ID_DEC_22 21
#define ID_DEC_21 20
#define ID_DEC_20 19
#define ID_DEC_19 18
#define ID_DEC_18 17
#define ID_DEC_17 16
#define ID_DEC_16 15
#define ID_DEC_15 14
#define ID_DEC_14 13
#define ID_DEC_13 12
#define ID_DEC_12 11
#define ID_DEC_11 10
#define ID_DEC_10 9
#define ID_DEC_9 8
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

#define CUE_ASSERT_EQ(actual, expected) \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		int _i_act_t = (actual);\
		int _i_exp_t = (expected);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Unexpect value\n\texpect: %d\n\tactual: %d", _i_exp_t, _i_act_t);\
		CU_assertImplementation((int)_i_act_t == (int)_i_exp_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_STRING_EQ(actual, expected) \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		const char *_i_act_t = (actual);\
		const char *_i_exp_t = (expected);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Unexpect string\n\texpect: [%s]\n\tactual: [%s]", _i_exp_t, _i_act_t);\
		CU_assertImplementation(0 == strcmp(_i_act_t, _i_exp_t), __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_PTR_EQ(actual, expected) \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		const void *_i_act_t = (actual);\
		const void *_i_exp_t = (expected);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Unexpect pointer\n\texpect: %p\n\tactual: %p", _i_exp_t, _i_act_t);\
		CU_assertImplementation((void*)_i_act_t == (void*)_i_exp_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_SUBJECT_SUCCEEDED() \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		int _i_code_t = ((int(*)())test_subject)();\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect called succeeded\n\tBut return(%d)", _i_code_t);\
		CU_assertImplementation(0==_i_code_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_SUBJECT_FAILED_WITH(err) \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		int _i_code_t = ((int(*)())test_subject)();\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect called failed with(%d)\n\tBut return(%d)", err, _i_code_t);\
		CU_assertImplementation(err==_i_code_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_STDOUT_EQ(out_fmt, ...) \
	do{\
		char _i_fmt_out[CUE_ASSERT_BUF_LEN];\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		const char *_i_sout_t = std_out;\
		snprintf(_i_fmt_out, sizeof(_i_fmt_out), out_fmt, ## __VA_ARGS__);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Unexpect stdout\n\texpect: [%s]\n\tactual: [%s]", _i_fmt_out, _i_sout_t);\
		CU_assertImplementation(0==strcmp(_i_sout_t, _i_fmt_out), __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_ASSERT_STDERR_EQ(err) \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		const char *_i_serr_t = std_err;\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Unexpect stderr\n\texpect: [%s]\n\tactual: [%s]", err, _i_serr_t);\
		CU_assertImplementation(0==strcmp(_i_serr_t, err), __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
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

#define extern_mock_function_0(rtype, func) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)();
#define mock_function_0(rtype, func) \
	int func ## _times;\
	rtype (*mock_ ## func)();\
	rtype func() {\
		static rtype default_result;\
		++func ## _times;\
		if(mock_ ## func)\
			return mock_ ## func();\
		return default_result;\
	}

#define extern_mock_function_1(rtype, func, t1) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)(t1);\
	extern t1 func ## _p1;
#define mock_function_1(rtype, func, t1) \
	int func ## _times;\
	t1 func ## _p1;\
	rtype (*mock_ ## func)(t1);\
	rtype func(t1 p1) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		if(mock_ ## func)\
			return mock_ ## func(p1);\
		return default_result;\
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

#define extern_mock_function_3(rtype, func, t1, t2, t3) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)(t1, t2, t3);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;
#define mock_function_3(rtype, func, t1, t2, t3) \
	int func ## _times;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	rtype (*mock_ ## func)(t1, t2, t3);\
	rtype func(t1 p1, t2 p2, t3 p3) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3);\
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

#define extern_mock_function_6(rtype, func, t1, t2, t3, t4, t5, t6) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;

#define mock_function_6(rtype, func, t1, t2, t3, t4, t5, t6) \
	int func ## _times;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6);\
	rtype func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		func ## _p6 = p6;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3, p4, p5, p6);\
		return default_result;\
	}

#define extern_mock_function_7(rtype, func, t1, t2, t3, t4, t5, t6, t7) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;
#define mock_function_7(rtype, func, t1, t2, t3, t4, t5, t6, t7) \
	int func ## _times;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7);\
	rtype func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		func ## _p6 = p6;\
		func ## _p7 = p7;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3, p4, p5, p6, p7);\
		return default_result;\
	}

#define extern_mock_function_8(rtype, func, t1, t2, t3, t4, t5, t6, t7, t8) \
	extern int func ## _times;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;\
	extern t8 func ## _p8;
#define mock_function_8(rtype, func, t1, t2, t3, t4, t5, t6, t7, t8) \
	int func ## _times;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	t8 func ## _p8;\
	rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8);\
	rtype func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		func ## _p6 = p6;\
		func ## _p7 = p7;\
		func ## _p8 = p8;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3, p4, p5, p6, p7, p8);\
		return default_result;\
	}

#define called_times_of(func) (func ## _times)

#define params_of(func, at) (func ## _p ## at)

#define init_mock_function(func, stub) \
	func ## _times = 0;\
	mock_ ## func = stub;
#define CUE_EXPECT_NEVER_CALLED(func)  \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		int _i_times_t = called_times_of(func);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect '%s' never called\n\tbut called %d times", #func, _i_times_t);\
		CU_assertImplementation(0==_i_times_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_EXPECT_CALLED_ONCE(func)  \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		int _i_times_t = called_times_of(func);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect '%s' called once\n\tbut called %d times", #func, _i_times_t);\
		CU_assertImplementation(1==_i_times_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_EXPECT_CALLED_WITH_STRING(func, at, arg) \
	CUE_EXPECT_CALLED_ONCE(func);\
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		const char *_i_exp_t = (arg);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect '%s' called with params[%d] string [%s]\n\tbut got [%s]", #func, at, _i_exp_t, params_of(func, at));\
		CU_assertImplementation(0 == strcmp((const char*)params_of(func, at), _i_exp_t), __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_EXPECT_CALLED_WITH_INT(func, at, arg) \
	CUE_EXPECT_CALLED_ONCE(func);\
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		int _i_exp_t = (arg);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect '%s' called with params[%d] int %d\n\tbut got %d", #func, at, _i_exp_t, params_of(func, at));\
		CU_assertImplementation((int)params_of(func, at) == (int)_i_exp_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_EXPECT_CALLED_WITH_PTR(func, at, arg) \
	CUE_EXPECT_CALLED_ONCE(func);\
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		const void *_i_exp_t = (arg);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect '%s' called with params[%d] pointer %p\n\tbut got %p", #func, at, _i_exp_t, params_of(func, at));\
		CU_assertImplementation((void *)params_of(func, at) == (void *)_i_exp_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#define CUE_EXPECT_CALLED_TIMES(func, t)  \
	do{\
		char _i_buf_t[CUE_ASSERT_BUF_LEN];\
		int _i_times_t = called_times_of(func);\
		int _times = (t);\
		snprintf(_i_buf_t, sizeof(_i_buf_t), "Expect '%s' called %d times\n\tbut called %d times", #func, _times, _i_times_t);\
		CU_assertImplementation(_times==_i_times_t, __LINE__, _i_buf_t, __FILE__, "", CU_FALSE);\
	} while(0)

#endif
