#define SECs ((double)clock() / CLOCKS_PER_SEC)
struct KeyHasher {
  size_t operator()(const Key& k) const {
    return k.first + k.second * 100000;
  }
};
typedef unordered_map<Key, int, KeyHasher> map_t;
__builtin_popcountll;  // 二進位有幾個1
__builtin_clzll;       // 左起第一個1之前0的個數
__builtin_parityll;    // popcount的奇偶性
__builtin_mul_overflow(a, b, &h)  // a*b是否溢位
__lg(x);               // floor(log2(x))
