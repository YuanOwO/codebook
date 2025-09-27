struct BIT {
  int n;
  vector<ll> bit;
  int lowbit(int x) { return x & -x; }
  BIT(int _n) : n(_n + 1) { bit = vector<ll>(_n + 1, 0); }
  void update(int x, ll v) {  // 將 x 的值加上 v
    for (; x < n; x += lowbit(x)) bit[x] += v;
  }
  ll query(int x) {  // 查詢區間 [1, x] 的總和
    ll ret = 0;
    for (; x; x -= lowbit(x)) ret += bit[x];
    return ret;
  }
  ll query(int l, int r) {  // 查詢區間 [l, r] 的總和
    return query(r) - query(l - 1);
  }
  int kth(int k) {
    int x = 0;
    for (int i = 1 << __lg(n); i; i >>= 1)
      if (x + i <= n && k >= bit[x + i - 1])
        x += i, k -= bit[x - 1];
    return x;
  }
};
