int cent;  // 這就是重心
void dfs(int u, int pre) {
  sz[u] = 1;
  int mx = 0;
  for (int& v : g[u]) {
    if (v == pre) continue;
    dfs(v, u);
    sz[u] += sz[v];
    mx = max(mx, sz[v]);
  }
  mx = max(mx, n - sz[u]);
  if (mx <= n / 2) cent = u;
}
