#define ll long long

const ll MXN = 2e6 + 5;
const ll MOD = 1e9 + 7;

/**
 * @brief factorial and it's modular inverse && 排列組合 shit
 *
 * 用法:
 * 1. 呼叫 init() 初始化
 * 2. 視情況呼叫 comb()、perm() 或 h()
 * 結果:
 * 1. 階乘及其模逆元會存在 fac[] 跟 inv[]
 * 2. comb()、perm() 或 h() 會算出結果
 * 備註: 注意數字大小不能超過 MXN
 *
 */

ll fac[MXN], inv[MXN];

void init() {
    fac[0] = 1;                   // 0! = 1
    for (ll i = 1; i < MXN; i++)  // factorial
        fac[i] = fac[i - 1] * i % MOD;
    // 費馬小定理(逆元) with 快速冪
    inv[MXN - 1] = power(fac[MXN - 1], MOD - 2);
    for (ll i = MXN - 2; i >= 0; i--)  // the inverse of factorial
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

// 組合 (Combination) n 取 k
ll comb(ll n, ll k) {
    // C(n, k) = n! / (k! * (n - k)!)
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
