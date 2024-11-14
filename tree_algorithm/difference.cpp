int tag[N], f[N], ans[N], root;
void add(int x, int y) {
  int lca = getLCA(x, y);
  tag[x]++;
  tag[y]++;
  tag[lca]--;
  if (lca != root) tag[f[lca]]--;
}
int dfs_add(int now, int fa) {
  int diff = tag[now];
  for (auto nxt : edge[now]) {
    if (nxt == fa) continue;
    diff += dfs_add(nxt, now);
  }
  return ans[now] = diff;
}
