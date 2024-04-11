#define ll long long

const ll MXN = 2e6 + 5;
const ll MOD = 1e9 + 7;
const ll N = 2e6;
ll fac[MXN], inv[MXN];

void init() {
    fac[0] = 1;  // 0! = 1
    for (ll i = 1; i < MXN; i++)
        fac[i] = fac[i - 1] * i % MOD;
    inv[MXN - 1] = FastPow(fac[MXN - 1], MOD - 2);  // 快速冪
    for (ll i = N - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % MOD;
}

// Combination (n 取 k) % mod
ll comb(ll n, ll k) {
    return fac[n] * inv[k] * inv[n - k];
}
