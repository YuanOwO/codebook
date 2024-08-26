/**
 * @brief Pollard's rho Algorithm
 *
 * 用法: 呼叫 fact(n)
 * 結果: ret 存入質因數
 * 複雜度: pollard_rho: O(n^(1/4))
 * 備註:
 * -- ret 需排序
 * -- n是質數時不能用，建議搭配 Miller-Rabin
 *
 */

vector<ll> ret;

ll mul(ll x, ll y, ll mod) {
    ll ret = x * y - (LL)((long double)x / mod * y) * mod;
    return ret < 0 ? ret + mod : ret;
    // return x * y % mod;  //// 如果數字大到需要開__int128就用這
}

ll f(ll x, ll c, ll mod) {
    return (mul(x, x, mod) + c) % mod;
}

ll pollard_rho(ll n) {
    ll c = 1, x = 0, y = 0, p = 2, q, t = 0;
    while (t++ % 128 or gcd(p, n) == 1) {
        if (x == y)
            c++, y = f(x = 2, c, n);
        if (q = mul(p, abs(x - y), n))
            p = q;
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
    }
    return gcd(p, n);
}

void fact(ll x) {  // 透過遞迴找質數
    if (miller_rabin(x)) {
        ret.push_back(x);
        return;
    }
    ll f = pollard_rho(x);
    fact(f);
    fact(x / f);
}
