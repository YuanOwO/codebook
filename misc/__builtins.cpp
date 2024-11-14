__builtin_clz(x);  // 由左至右遇到第一個 1 之前有多少個 0
__builtin_ctz(x);  // 由右至左遇到第一個 1 之前有多少個 0
__builtin_ffs(x);  // 由右至左遇到的第一個 1 是第幾位
__builtin_clrsb(x);  // 从最高位开始和符号位相同的位数。
__builtin_popcount(x);
__builtin_parity(x);               // popcount % 2
__builtin_mul_overflow(a, b, &h);  // a * b是否溢位
__lg(x);                           // floor(log2(x))
memset(arr, val, sizeof(arr));     // 陣列設值
