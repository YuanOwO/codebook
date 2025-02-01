bool vis[MXN], adj[MXN][MXN];
int S[MXN];  // 其中 adj 為鄰接表, S 為紀錄這個點與誰匹配
int n, p, ans;  // n: 左集合數量, p: 右集合數量
bool tag[MXN];  // 紀錄是否被配對過

bool dfs(int u) {                         // 找最大匹配
  for (int i = n + 1; i <= n + p; i++) {  // 跑右集合
    if (adj[u][i] && !vis[i]) {       // 有連通且未拜訪
      vis[i] = 1;                     // 紀錄是否走過
      if (S[i] == -1 || dfs(S[i])) {  // 紀錄匹配
        S[i] = u, tag[u] = true;
        return true;  // 反轉匹配邊以及未匹配邊的狀態
      }
    }
  }
  return false;
}

void solve() {  // 記得每次使用需清空 vis
  for (int i = 1; i <= n + p; i++) S[i] = -1;
  ans = 0;
  for (int i = 1; i <= n; i++) {  // 跑左集合
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) ans++;
  }
}
