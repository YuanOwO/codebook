#define PB push_back
#define FZ(x) memset(x, 0, sizeof(x))  // fill zero
const int MXN = 2e5 + 5;

/**
 * @brief Kosaraju's Algorithm for searching SCC
 *
 * 強連通分量 Strongly Connected Components:
 * 圖中任兩點 u, v 必包含 u -> v 和 v -> u 的路徑
 *
 * 用法:
 * 1. init(n) 初始化圖 其中 n 為節點點數
 * 2. addEdge(u, v) 加入 u -> v 的有向邊
 * 3. solve()跑 SCC
 * 結果:
 * - bln[i]: 第 i 個節點屬於的 SCC 編號為 bln[i]
 * - nScc: 強連通分量 SCC 數量
 */

struct Scc {
    int n, nScc, vst[MXN], bln[MXN];
    vector<int> E[MXN], rE[MXN], vec;
    void init(int _n) {
        n = _n;
        for (int i = 0; i <= n; i++)
            E[i].clear(), rE[i].clear();
    }
    void addEdge(int u, int v) {
        E[u].PB(v);
        rE[v].PB(u);
    }
    void DFS(int u) {
        vst[u] = 1;
        for (auto v : E[u])
            if (!vst[v])
                DFS(v);
        vec.PB(u);
    }
    void rDFS(int u) {
        vst[u] = 1;
        bln[u] = nScc;  // 編號是 0-base
        for (auto v : rE[u])
            if (!vst[v])
                rDFS(v);
    }
    void solve() {
        nScc = 0;
        vec.clear();
        fill(vst, vst + n + 1, 0);
        for (int i = 0; i < n; i++)
            if (!vst[i])
                DFS(i);
        reverse(vec.begin(), vec.end());
        fill(vst, vst + n + 1, 0);
        for (auto v : vec)
            if (!vst[v]) {
                rDFS(v);
                nScc++;
            }
    }
};
