int __builtin_clz(unsigned int x);
int __builtin_clzl(unsigned long x);
int __builtin_clzll(unsigned long long x);

int __builtin_ctz(unsigned int x);
int __builtin_ctzl(unsigned long x);
int __builtin_ctzll(unsigned long long x);

int __builtin_ffs(int x);
int __builtin_ffsl(long x);
int __builtin_ffsll(long long x);

int __builtin_clrsb(int x);
int __builtin_clrsbl(long x);
int __builtin_clrsbll(long long x);

int __builtin_popcount(unsigned int x);
int __builtin_popcountl(unsigned long x);
int __builtin_popcountll(unsigned long long x);

int __builtin_parity(unsigned int x);
int __builtin_parityl(unsigned long x);
int __builtin_parityll(unsigned long long x);

uint16_t __builtin_bswap16(uint16_t x);
uint32_t __builtin_bswap32(uint32_t x);
uint64_t __builtin_bswap64(uint64_t x);
// uint128_t __builtin_bswap128(uint128_t x);

inline int __lg(int __n) {
  return sizeof(int) * __CHAR_BIT__ - 1 -
         __builtin_clz(__n);
}
inline long __lg(long __n) {
  return sizeof(long) * __CHAR_BIT__ - 1 -
         __builtin_clzl(__n);
}
inline long long __lg(long long __n) {
  return sizeof(long long) * __CHAR_BIT__ - 1 -
         __builtin_clzll(__n);
}
