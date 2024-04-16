#include <vector>
#define ll long long

using namespace std;

/**
 * @brief 樹狀數組 (Binary Indexed Tree)
 */
struct BIT {
#define lowbit(x) (x & -x)

    int n;
    vector<ll> a;

    BIT(int _n) {
        n = _n;
        a.clear();
        a.resize(n + 1, 0);
    }

    /**
     * @brief 將 x 的值加上 v
     */
    void update(int x, int v) {
        for (; x < a.size(); x += lowbit(x))
            a[x] += v;
    }

    /**
     * @brief 查詢區間 [1, x] 的總和
     */
    ll query(int x) {
        ll ret = 0;
        for (; x; x -= lowbit(x))
            ret += a[x];
        return ret;
    }

    /**
     * @brief 查詢區間 [l, r] 的總和
     */
    ll query(int l, int r) {
        return query(r) - query(l - 1);
    }

    int kth(int k) {
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
