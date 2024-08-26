#define ll long long
#define lowbit(x) (x & -x)

/**
 * @brief 樹狀數組 (Binary Indexed Tree)
 * 處理區間加總問題
 *
 * 用法:
 * 1. 初始化: 宣告 BIT 結構時傳入大小 n
 * 2. 存數字: 呼叫 update() 傳入位置與數值
 * 3. 找區間和: 呼叫 query() 傳入左界及右界位置
 * -- 修改某位置的值: 呼叫 update() 傳入位置與要加的數值
 * 結果: 得到答案
 * 備註: 如果怕取到位宣告空間 初始化時可以開大一點
 */
struct BIT {
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
