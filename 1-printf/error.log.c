For /home/egarcia2/francinette/tests/printf/printfTester/tests/s_test.cpp:
36: 	TEST(10, print(" NULL %s NULL ", NULL));

For /home/egarcia2/francinette/tests/printf/printfTester/tests/p_test.cpp:
33: 	TEST(9, print(" %p %p ", 0, 0));

For /home/egarcia2/francinette/tests/printf/printfTester/tests/x_test.cpp:
26: 	TEST(2, print(" %x ", -1));
37: 	TEST(13, print(" %x ", -9));
38: 	TEST(14, print(" %x ", -10));
39: 	TEST(15, print(" %x ", -11));
40: 	TEST(16, print(" %x ", -14));
41: 	TEST(17, print(" %x ", -15));
42: 	TEST(18, print(" %x ", -16));
43: 	TEST(19, print(" %x ", -99));
44: 	TEST(20, print(" %x ", -100));
45: 	TEST(21, print(" %x ", -101));
47: 	TEST(23, print(" %x ", INT_MIN));
48: 	TEST(24, print(" %x ", LONG_MAX));
50: 	TEST(26, print(" %x ", UINT_MAX));
51: 	TEST(27, print(" %x ", ULONG_MAX));
52: 	TEST(28, print(" %x ", 9223372036854775807LL));
53: 	TEST(29, print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
55: 	TEST(31, print(" %x ", -42));

For /home/egarcia2/francinette/tests/printf/printfTester/tests/upperx_test.cpp:
26: 	TEST(2, print(" %X ", -1));
37: 	TEST(13, print(" %X ", -9));
38: 	TEST(14, print(" %X ", -10));
39: 	TEST(15, print(" %X ", -11));
40: 	TEST(16, print(" %X ", -14));
41: 	TEST(17, print(" %X ", -15));
42: 	TEST(18, print(" %X ", -16));
43: 	TEST(19, print(" %X ", -99));
44: 	TEST(20, print(" %X ", -100));
45: 	TEST(21, print(" %X ", -101));
47: 	TEST(23, print(" %X ", INT_MIN));
48: 	TEST(24, print(" %X ", LONG_MAX));
50: 	TEST(26, print(" %X ", UINT_MAX));
51: 	TEST(27, print(" %X ", ULONG_MAX));
52: 	TEST(28, print(" %X ", 9223372036854775807LL));
53: 	TEST(29, print(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
55: 	TEST(31, print(" %X ", -42));

For /home/egarcia2/francinette/tests/printf/printfTester/tests/mix_test.cpp:
25: 	TEST(1, print("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));

