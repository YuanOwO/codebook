#define ll long long

const ll MXN = 2e6 + 5;
const ll MOD = 1e9 + 7;

/**
 * @brief 最大公因數
 *
 * @param a A
 * @param b B
 * @return ll A 和 B 的最大公因數
 */
ll gcd(ll a, ll b) {
    if (b)
        while ((a %= b) && (b %= a))
            ;  // 不要問我這尛
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

/**
 * @brief 快速冪取模
 * 計算 x 的 y 次方對 mod 取模之值
 *
 * @param x 底數
 * @param y 指數
 * @param mod 求模的那個東東
 * @return ll x 的 y 次方之值
 */
ll power(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1)
            (ret *= x) %= MOD;
        (x *= x) %= MOD;
        y >>= 1;
    }
    return ret;
}

ll fac[MXN], inv[MXN];

void init() {
    fac[0] = 1;  // 0! = 1
    for (ll i = 1; i < MXN; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MXN - 1] = power(fac[MXN - 1], MOD - 2);  // 費馬小定理 with 快速冪
    for (ll i = MXN - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

// 組合 (Combination) n 取 k
ll comb(ll n, ll k) {
    return fac[n] * inv[k] % MOD * inv[n - k] % MOD;
}

// 排列 (Permutation) n 取 k
ll perm(ll n, ll k) {
    // P(n, k) = C(n, k) * k!
    return fac[n] * inv[n - k] % MOD;
}

// 重複組合 (Combinations WITH Repetitions)
ll h(ll n, ll k) {
    // H(n, k) = C(n + k - 1, n - 1)
    return fac[n + k - 1] * inv[k] % MOD * inv[n - 1] % MOD;
}
