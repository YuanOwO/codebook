#define lowbit(x) (x & -x)
struct BIT {
    int n;
    vector<ll> a;
    BIT(int _n) {
        n = _n;
        a.clear();
        a.resize(n + 1, 0);
    }
    void update(int x, int v) {  // 將 x 的值加上 v
        for (; x < a.size(); x += lowbit(x))
            a[x] += v;
    }
    ll query(int x) {  // 查詢區間 [1, x] 的總和
        ll ret = 0;
        for (; x; x -= lowbit(x))
            ret += a[x];
        return ret;
    }
    // 查詢區間 [l, r] 的總和
    ll query(int l, int r) {  // 大多呼叫這個為主
        return query(r) - query(l - 1);
    }
    int kth(int k) {  // 說實話這不常用 有時可以刪掉
        int x = 0;
        for (int i = 1 << __lg(n); i; i >>= 1) {
            if (x + i <= n && k >= a[x + i - 1]) {
                x += i;
                k -= a[x - 1];
            }
        }
        return x;
    }
};
