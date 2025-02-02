vector<int> g[MXN];
bool vis[MXN];
int S[MXN];  // S 為紀錄這個點與誰匹配
int n, ans;  // n: 左集合數量, ans: 紀錄答案

bool dfs(int u) {  // 找最大匹配
  for (int &v : g[u]) {
    if (!vis[v]) {
      vis[v] = true;
      if (S[v] == -1 || dfs(S[v])) {
        S[v] = u;
        return true;
      }
    }
  }
  return false;
}

void solve() {  // 記得每次使用需清空 vis
  memset(S, -1, sizeof(S));
  ans = 0;
  for (int i = 1; i <= n; i++) {  // 跑左集合
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) ans++;
  }
}
