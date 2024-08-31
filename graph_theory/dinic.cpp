#define SZ(x) (int)x.size()
#define PB push_back
const int MXN = 1e5 + 5;
/**
 * @brief Dinic's algorithm
 * Finding maximum flow
 *
 * 用法:
 * 1. 初始化 init(_n, _s, _t)
 *    其中 _n 是節點數 _s 是源點 _t 是匯點
 * 2. add_edge(u, v, f) 加入邊
 *    其中 u 起點 v 終點 f 流量
 * 3. flow() 回傳最大流量答案
 * 結果: 算出圖的最大流量
 * 備註:
 * - 注意資料型態 (如果要用 long long)
 * - 圖必須是 0-base
 * - 圖是有像圖
 *
 */

struct Dinic {
    struct Edge {
        int v, f, re;
    };
    int n, s, t, level[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t) {
        n = _n;
        s = _s;
        t = _t;
        for (int i = 0; i < n; i++)
            E[i].clear();
    }
    void add_edge(int u, int v, int f) {
        E[u].PB({v, f, SZ(E[v])});
        E[v].PB({u, 0, SZ(E[u]) - 1});
    }
    bool BFS() {
        for (int i = 0; i < n; i++)
            level[i] = -1;
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto it : E[u]) {
                if (it.f > 0 && level[it.v] == -1) {
                    level[it.v] = level[u] + 1;
                    que.push(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    int DFS(int u, int nf) {
        if (u == t)
            return nf;
        int res = 0;
        for (auto &it : E[u]) {
            if (it.f > 0 && level[it.v] == level[u] + 1) {
                int tf = DFS(it.v, min(nf, it.f));
                res += tf;
                nf -= tf;
                it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0)
                    return res;
            }
        }
        if (!res)
            level[u] = -1;
        return res;
    }
    int flow(int res = 0) {
        while (BFS())
            res += DFS(s, 2147483647);
        return res;
    }
} flow;
