struct Scc {  // 新的 DAG 可能會有多重邊
#define PB push_back
  int n, nScc, vst[MXN], bln[MXN];
  vector<int> E[MXN], rE[MXN], vec, dag[MXN];
  set<int> vis[MXN];
  void init(int _n) {
    n = _n;
    for (int i = 0; i <= n; i++) {
      E[i].clear(), rE[i].clear();
      dag[i].clear(), vis[i].clear();
      bln[i] = -1;
    }
  }
  void addEdge(int u, int v) {
    E[u].PB(v);
    rE[v].PB(u);
  }
  void DFS(int u) {
    vst[u] = 1;
    for (auto v : E[u])
      if (!vst[v]) DFS(v);
    vec.PB(u);
  }
  void rDFS(int u) {
    vst[u] = 1;
    bln[u] = nScc;  // 編號是 0-base
    for (auto v : rE[u])
      if (!vst[v]) rDFS(v);
  }
  void build_new_dag() {
    for (int i = 0; i < n; i++) {
      for (int &j : E[i]) {
        if (bln[i] != bln[j] &&
            vis[bln[i]].count(bln[j]) == 0) {
          dag[bln[i]].push_back(bln[j]);
          vis[bln[i]].insert(bln[j]);
        }
      }
    }
  }
  void solve() {
    nScc = 0;
    vec.clear();
    fill(vst, vst + n + 1, 0);
    for (int i = 0; i < n; i++)
      if (!vst[i]) DFS(i);
    reverse(vec.begin(), vec.end());
    fill(vst, vst + n + 1, 0);
    for (auto v : vec) {
      if (!vst[v]) {
        rDFS(v);
        nScc++;
      }
    }
    build_new_dag();
  }
};
