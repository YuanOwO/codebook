#include <algorithm>
#include <vector>

using namespace std;

const int MXN = 2e6;

/**
 * @brief 併查集 (Disjoint Set)
 */
struct DSU {
    int n;
    vector<int> f, sz;

    DSU(int _n) {
        n = _n;
        f.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }

    /**
     * @brief 返回 x 的根節點
     */
    int find(int x) {
        if (x == f[x])
            return x;
        return f[x] = find(f[x]);
    }

    /**
     * @brief 將 x 和 y 合併在一起
     */
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])  // 將小的併入大的
            swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
    }
};
