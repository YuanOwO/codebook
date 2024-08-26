#define ll long long
/**
 * @brief Miller-Rabin test for prime test
 * 判斷質數 O(klog^3(n))
 *
 * 測試數列 magic
 * n < 4,759,123,141       3 :  2, 7, 61
 * n < 1,122,004,669,633   4 :  2, 13, 23, 1662803
 * n < 3,474,749,660,383   6 :  pirmes <= 13
 * n < 2^64       7 :  2, 325, 9375, 28178, 450775, 9780504, 1795265022
 * 要確定要判斷的整數 n 是介於 [2, n - 2] if you want to use magic.
 *
 * @param n 整數
 * @return 是否為質數
 */

ll mul(ll x, ll y, ll mod) {
    ll ret = x * y - (LL)((long double)x / mod * y) * mod;
    return ret < 0 ? ret + mod : ret;

    // return x * y % mod;  //// 如果數字大到需要開__int128就用這
}

ll magic[] = {};  // 這邊填入要用於測試的數列
ll S = 3;         // 測試的數列數字的數量
bool witness(ll a, ll n, ll u, int t) {
    if (!a)
        return 0;
    ll x = power(a, u, n);
    for (int i = 0; i < t; i++) {
        ll nx = mul(x, x, n);
        if (nx == 1 && x != 1 && x != n - 1)
            return 1;
        x = nx;
    }
    return x != 1;
}
bool miller_rabin(ll n) {
    int s = S;  // magic number size
    // iterate s times of witness on n
    if (n < 2)
        return false;
    if (!(n & 1))
        return (n == 2);

    // 將 n - 1 寫成 u * (2 ^ t) 的形式
    ll u = n - 1;
    int t = 0;
    while (!(u & 1))
        u >>= 1, t++;

    while (s--) {
        ll a = magic[s] % n;
        if (witness(a, n, u, t))
            return false;
    }
    return true;
}
