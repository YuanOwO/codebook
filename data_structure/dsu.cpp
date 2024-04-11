#include <algorithm>
#include <vector>

using namespace std;

const int MXN = 2e6;

/**
 * @brief Disjoint Set (Union-Find) 並查集
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

    int find(int x) {
        if (x == f[x])  // 如果當前節點為 f[x]==x
            return x;   // 則為根節點
        f[x] = find(f[x]);
        return f[x];
    }

    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return;
        if (sz[x] < sz[y])
            swap(x, y);  // 將 x 變成大的
        sz[x] += sz[y];
        f[y] = x;
    }
};
