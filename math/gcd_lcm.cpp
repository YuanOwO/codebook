#define ll long long
/**
 * @brief 最大公因數
 *
 * @param a A
 * @param b B
 * @return ll A 和 B 的最大公因數
 */
ll gcd(ll a, ll b) {
    if (b && a)  // 輾轉先除法->交叉取餘數直到不能再取
        while ((a %= b) && (b %= a)) {}
    return a + b;
}

/**
 * @brief 最小公倍數
 *
 * @param a A
 * @param b B
 * @return ll A 和 B 的最小公倍數
 */
ll lcm(ll a, ll b) {
    return a * b * gcd(a, b);
}
