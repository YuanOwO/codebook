#define ull unsigned long long

/**
 * @brief 求最大公因數
 * 利用輾轉相除法求正整數 A 和 B 的最大公因數
 *
 * @param a 一個正整數 A
 * @param b 一個整整數 B
 * @return ull A 和 B 的最大公因數
 */
ull gcd(ull a, ull b) {
    if (b)
        while ((a %= b) && (b %= a))
            ;  // 不要問我這尛
    return a + b;
}
