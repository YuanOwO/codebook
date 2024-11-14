vector<int> edge[MAXN];
void dfs(int u, int pre) {
  for (int v : edge[u]) {
    if (pre == v) continue;
    dfs(v, u);
  }
}
