ll P1 = 75577, P2 = 12721, MOD = 998244353;
pii hashs[MAXN], hashs2[MAXN];
string s1, s2;
void build(string s, pii hash) {
    ll val1 = 0, val2 = 0;
    for (int i = 0; i < s.length(); i++) {
        val1 = (val1 * P1 % MOD + s[i]) % MOD;
        val2 = (val2 * P2 % MOD + s[i]) % MOD;
        hash[i] = {val1, val2};
    }
}
ll minus(ll a, ll b) {
    return (a - b + MOD) % MOD;
}
ll cnt_occur() {  // 檢查
    int n = s1.size(), k = s2.size();
    ll cnt = (hashs2[k - 1].x == hashs[k - 1].x &&
              hashs2[k - 1].y == hashs[k - 1].y);
    ll val1 = 0, val2 = 0;
    for (int i = 1, j = k; j < n; j++, i++) {
        val1 = minus(hashs[j].x, hashs[i - 1].x * fpow(P1, j - i + 1));
        val2 = minus(hashs[j].y, hashs[i - 1].y * fpow(P1, j - i + 1));
        if (hashs2[k - 1].x == val1 && hashs2[k - 1].y == val2)
            cnt++;
    }
}
