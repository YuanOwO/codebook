#define SZ(x) ((int)x.size())
#define PB push_back
struct Dinic {
  struct Edge {
    int v;
    ll f;
    int re;
  };
  int n, s, t, level[MXN], cur[MXN];
  vector<Edge> E[MXN];
  void init(int _n, int _s, int _t) {
    n = _n;
    s = _s;
    t = _t;
    for (int i = 0; i < n; i++) E[i].clear();
  }
  void add_edge(int u, int v, int f) {
    E[u].PB({v, f, SZ(E[v])});
    E[v].PB({u, 0, SZ(E[u]) - 1});
  }
  bool BFS() {
    for (int i = 0; i < n; i++) level[i] = -1, cur[i] = 0;
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
  ll DFS(int u, ll nf) {
    if (u == t) return nf;
    int res = 0;
    for (int& i = cur[u]; i < (int)E[u].size(); i++) {
      Edge& it = E[u][i];
      if (it.f > 0 && level[it.v] == level[u] + 1) {
        int tf = DFS(it.v, min(nf, it.f));
        res += tf;
        nf -= tf;
        it.f -= tf;
        E[it.v][it.re].f += tf;
        if (nf == 0) return res;
      }
    }
    if (!res) level[u] = -1;
    return res;
  }
  ll flow(ll res = 0) {
    while (BFS()) res += DFS(s, 2147483647);
    return res;
  }
} flow;
