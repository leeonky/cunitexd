#define extern_mock_void_function_0(func) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)();
#define mock_void_function_0(func) \
	int func ## _times;\
	int func ## _set_return;\
	void (*mock_ ## func)();\
	void func() {\
		++func ## _times;\
		if(mock_ ## func)\
			mock_ ## func();\
	}

#define extern_mock_void_function_1(func, t1) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1);\
	extern t1 func ## _p1;
#define mock_void_function_1(func, t1) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	void (*mock_ ## func)(t1);\
	void func(t1 p1) {\
		++func ## _times;\
		func ## _p1 = p1;\
		if(mock_ ## func)\
			mock_ ## func(p1);\
	}

#define extern_mock_void_function_2(func, t1, t2) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;
#define mock_void_function_2(func, t1, t2) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	void (*mock_ ## func)(t1, t2);\
	void func(t1 p1, t2 p2) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2);\
	}

#define extern_mock_void_function_3(func, t1, t2, t3) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;
#define mock_void_function_3(func, t1, t2, t3) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	void (*mock_ ## func)(t1, t2, t3);\
	void func(t1 p1, t2 p2, t3 p3) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2, p3);\
	}

#define extern_mock_void_function_4(func, t1, t2, t3, t4) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3, t4);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;
#define mock_void_function_4(func, t1, t2, t3, t4) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	void (*mock_ ## func)(t1, t2, t3, t4);\
	void func(t1 p1, t2 p2, t3 p3, t4 p4) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2, p3, p4);\
	}

#define extern_mock_void_function_5(func, t1, t2, t3, t4, t5) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3, t4, t5);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;
#define mock_void_function_5(func, t1, t2, t3, t4, t5) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	void (*mock_ ## func)(t1, t2, t3, t4, t5);\
	void func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2, p3, p4, p5);\
	}

#define extern_mock_void_function_6(func, t1, t2, t3, t4, t5, t6) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3, t4, t5, t6);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;
#define mock_void_function_6(func, t1, t2, t3, t4, t5, t6) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	void (*mock_ ## func)(t1, t2, t3, t4, t5, t6);\
	void func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		func ## _p6 = p6;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2, p3, p4, p5, p6);\
	}

#define extern_mock_void_function_7(func, t1, t2, t3, t4, t5, t6, t7) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;
#define mock_void_function_7(func, t1, t2, t3, t4, t5, t6, t7) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7);\
	void func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		func ## _p6 = p6;\
		func ## _p7 = p7;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2, p3, p4, p5, p6, p7);\
	}

#define extern_mock_void_function_8(func, t1, t2, t3, t4, t5, t6, t7, t8) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;\
	extern t8 func ## _p8;
#define mock_void_function_8(func, t1, t2, t3, t4, t5, t6, t7, t8) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	t8 func ## _p8;\
	void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8);\
	void func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8) {\
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
			mock_ ## func(p1, p2, p3, p4, p5, p6, p7, p8);\
	}

#define extern_mock_void_function_9(func, t1, t2, t3, t4, t5, t6, t7, t8, t9) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;\
	extern t8 func ## _p8;\
	extern t9 func ## _p9;
#define mock_void_function_9(func, t1, t2, t3, t4, t5, t6, t7, t8, t9) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	t8 func ## _p8;\
	t9 func ## _p9;\
	void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9);\
	void func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		func ## _p6 = p6;\
		func ## _p7 = p7;\
		func ## _p8 = p8;\
		func ## _p9 = p9;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2, p3, p4, p5, p6, p7, p8, p9);\
	}

#define extern_mock_void_function_10(func, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;\
	extern t8 func ## _p8;\
	extern t9 func ## _p9;\
	extern t10 func ## _p10;
#define mock_void_function_10(func, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) \
	int func ## _times;\
	int func ## _set_return;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	t8 func ## _p8;\
	t9 func ## _p9;\
	t10 func ## _p10;\
	void (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);\
	void func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9, t10 p10) {\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		func ## _p6 = p6;\
		func ## _p7 = p7;\
		func ## _p8 = p8;\
		func ## _p9 = p9;\
		func ## _p10 = p10;\
		if(mock_ ## func)\
			mock_ ## func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);\
	}

#define extern_mock_function_0(rtype, func) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)();
#define mock_function_0(rtype, func) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
	rtype (*mock_ ## func)();\
	rtype func() {\
		static rtype default_result;\
		++func ## _times;\
		if(mock_ ## func)\
			return mock_ ## func();\
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_1(rtype, func, t1) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1);\
	extern t1 func ## _p1;
#define mock_function_1(rtype, func, t1) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
	t1 func ## _p1;\
	rtype (*mock_ ## func)(t1);\
	rtype func(t1 p1) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		if(mock_ ## func)\
			return mock_ ## func(p1);\
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_2(rtype, func, t1, t2) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1, t2);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;
#define mock_function_2(rtype, func, t1, t2) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
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
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_3(rtype, func, t1, t2, t3) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1, t2, t3);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;
#define mock_function_3(rtype, func, t1, t2, t3) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
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
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_4(rtype, func, t1, t2, t3, t4) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;
#define mock_function_4(rtype, func, t1, t2, t3, t4) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
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
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_5(rtype, func, t1, t2, t3, t4, t5) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4, t5);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;
#define mock_function_5(rtype, func, t1, t2, t3, t4, t5) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	rtype (*mock_ ## func)(t1, t2, t3, t4, t5);\
	rtype func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5) {\
		static rtype default_result;\
		++func ## _times;\
		func ## _p1 = p1;\
		func ## _p2 = p2;\
		func ## _p3 = p3;\
		func ## _p4 = p4;\
		func ## _p5 = p5;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3, p4, p5);\
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_6(rtype, func, t1, t2, t3, t4, t5, t6) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;
#define mock_function_6(rtype, func, t1, t2, t3, t4, t5, t6) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
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
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_7(rtype, func, t1, t2, t3, t4, t5, t6, t7) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
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
	int func ## _set_return;\
	rtype func ## _return_value;\
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
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_8(rtype, func, t1, t2, t3, t4, t5, t6, t7, t8) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
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
	int func ## _set_return;\
	rtype func ## _return_value;\
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
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_9(rtype, func, t1, t2, t3, t4, t5, t6, t7, t8, t9) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;\
	extern t8 func ## _p8;\
	extern t9 func ## _p9;
#define mock_function_9(rtype, func, t1, t2, t3, t4, t5, t6, t7, t8, t9) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	t8 func ## _p8;\
	t9 func ## _p9;\
	rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9);\
	rtype func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9) {\
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
		func ## _p9 = p9;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3, p4, p5, p6, p7, p8, p9);\
		return func ## _set_return ? func ## _return_value : default_result;\
	}

#define extern_mock_function_10(rtype, func, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) \
	extern int func ## _times;\
	extern int func ## _set_return;\
	extern rtype func ## _return_value;\
	extern rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);\
	extern t1 func ## _p1;\
	extern t2 func ## _p2;\
	extern t3 func ## _p3;\
	extern t4 func ## _p4;\
	extern t5 func ## _p5;\
	extern t6 func ## _p6;\
	extern t7 func ## _p7;\
	extern t8 func ## _p8;\
	extern t9 func ## _p9;\
	extern t10 func ## _p10;
#define mock_function_10(rtype, func, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10) \
	int func ## _times;\
	int func ## _set_return;\
	rtype func ## _return_value;\
	t1 func ## _p1;\
	t2 func ## _p2;\
	t3 func ## _p3;\
	t4 func ## _p4;\
	t5 func ## _p5;\
	t6 func ## _p6;\
	t7 func ## _p7;\
	t8 func ## _p8;\
	t9 func ## _p9;\
	t10 func ## _p10;\
	rtype (*mock_ ## func)(t1, t2, t3, t4, t5, t6, t7, t8, t9, t10);\
	rtype func(t1 p1, t2 p2, t3 p3, t4 p4, t5 p5, t6 p6, t7 p7, t8 p8, t9 p9, t10 p10) {\
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
		func ## _p9 = p9;\
		func ## _p10 = p10;\
		if(mock_ ## func)\
			return mock_ ## func(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);\
		return func ## _set_return ? func ## _return_value : default_result;\
	}

