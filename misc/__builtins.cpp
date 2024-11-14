__builtin_clzll(x);  // 由左至右遇到第一個1之前有多少個0
__builtin_ctzll(x);  // 由右至左遇到第一個1之前有多少個0
__builtin_ffsll(x);  // 由右至左遇到的第一個1是第幾位
__builtin_clrsbll(x);  // 从最高位開始和符号位相同的位數。
__builtin_popcountll(x);
__builtin_parityll(x);             // popcount % 2
__builtin_mul_overflow(a, b, &h);  // a * b 是否溢位
__lg(x);                           // floor(log2(x))
memset(arr, val, sizeof(arr));     // 陣列設值
