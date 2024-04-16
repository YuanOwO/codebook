/**
 * 一些 built-in functions 的筆記與替代實作
 */
#include <iostream>
#include <numeric>
#define ll long long
#define ull unsigned long long

using namespace std;

/**
 * Count Leading Zeros
 *
 * Returns the number of leading 0-bits in x, starting at the most
 * significant bit position. If x is 0, the result is undefined.
 *
 * 回傳 由左至右 (最高位開始數)，遇到第一個 1 之前，有多少個 0-bits
 */
int clz64(ull x) {
    for (int i = 0; i != 64; ++i)
        if (x >> 63 - i & 1)
            return i;
}

int __builtin_clz(unsigned int x);
int __builtin_clzl(unsigned long x);
int __builtin_clzll(unsigned long long x);

/**
 * Counting Trailing Zeros
 *
 * Returns the number of trailing 0-bits in x, starting at the least
 * significant bit position. If x is 0, the result is undefined.
 *
 * 回傳 由右至左 (最低位開始數)，遇到第一個 1 之前，有多少個 0-bits
 * 當 x = 0 時未定義
 */
int ctz64(ull x) {
    for (int i = 0; i != 64; ++i)
        if (x >> i & 1)
            return i;
    return 0;
}

int __builtin_ctz(unsigned int x);
int __builtin_ctzl(unsigned long x);
int __builtin_ctzll(unsigned long long x);

/**
 * Find First Set
 *
 * Returns one plus the index of the least significant 1-bit of x, or if
 * x is zero, returns zero.
 *
 * 回傳 由右至左 (最低位開始數)，遇到的第一個 1 是第幾位
 * 當 x = 0 時回傳 0
 */
int ffs64(ll x) {
    if (x == 0)
        return 0;
    return ctz64(x) + 1;
}

int __builtin_ffs(int x);
int __builtin_ffsl(long x);
int __builtin_ffsll(long long x);

/**
 * Count Leading Redundant Sign Bits
 *
 * Returns the number of leading redundant sign bits in x, i.e. the
 * number of bits following the most significant bit that are identical
 * to it. There are no special cases for 0 or other values.
 *
 * 回傳 从最高位（MSB）开始和符号位相同的位数。
 * 當 x = 0 時未定義
 */
int clrsb64(ull x) {
    if (x == 0 || x == -1)
        return 63;
    return clz64(x ^ x >> 63);
}

int __builtin_clrsb(int x);
int __builtin_clrsbl(long x);
int __builtin_clrsbll(long long x);

/**
 * Population Count
 *
 * Returns the number of 1-bits in x.
 *
 * 回傳 數字中 1-bits 的數量
 */
int popcount(ull x) {
    int ret = 0;
    do {
        ret += x & 1;
    } while (x >>= 1);
    return ret;
}

int __builtin_popcount(unsigned int x);
int __builtin_popcountl(unsigned long x);
int __builtin_popcountll(unsigned long long x);

/**
 * Returns the parity of x, i.e. the number of 1-bits in x
 * modulo 2.
 *
 * 回傳 數字中 1-bits 數量的奇偶性 (popcount % 2)
 */
int parity(ull x) {
    return popcount(x) & 1;
}

int __builtin_parity(unsigned int x);
int __builtin_parityl(unsigned long x);
int __builtin_parityll(unsigned long long x);

/**
 * Returns x with the order of the bytes reversed; for example, 0xaabb
 * becomes 0xbbaa. Byte here always means exactly 8 bits.
 */
uint16_t __builtin_bswap16(uint16_t x);
uint32_t __builtin_bswap32(uint32_t x);
uint64_t __builtin_bswap64(uint64_t x);
// uint128_t __builtin_bswap128(uint128_t x);

/**
 * This is a helper function for the sort routines and for random.tcc.
 * Precondition: __n > 0.
 *
 * 表示该数二进制表示下最高一位 1 的位置
 * floor(log2(x))
 */
inline int __lg(int __n) {
    return sizeof(int) * __CHAR_BIT__ - 1 - __builtin_clz(__n);
}
inline long __lg(long __n) {
    return sizeof(long) * __CHAR_BIT__ - 1 - __builtin_clzl(__n);
}
inline long long __lg(long long __n) {
    return sizeof(long long) * __CHAR_BIT__ - 1 - __builtin_clzll(__n);
}
