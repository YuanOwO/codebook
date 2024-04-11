#define ll long long

/**
 * @brief 快速冪取模
 * 計算 x 的 y 次方對 mod 取模之值
 *
 * @param x 底數
 * @param y 指數
 * @param mod 求模的那個東東
 * @return ll x 的 y 次方之值
 */
ll power(ll x, ll y, ll mod = 0x7fffffffffffffffLL) {
    ll ans = 1;
    while (y) {
        if (y & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
