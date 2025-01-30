typedef pair<int, int> pii;
vector<pii> g[MAXN];  // 儲存鄰接陣列: g[u] = {v, w}
int n, m;             // 節點數、邊數

int prim(int start) {  // 0-based
  vector<bool> vis(n, false);
  vector<int> key(n, INT_MAX);
  vector<int> f(n);

  f[start] = -1;  // 起點沒有父親
  key[start] = 0;

  for (int i = 0; i < n - 1; i++) {
    // 最多只會走 n - 1 條邊
    int mn = INT_MAX, idx = 0;
    for (int j = 0; j < n; j++) {
      if (!vis[j] && mn > key[j]) mn = key[j], idx = j;
    }

    vis[idx] = true;
    int u = idx;
    for (pii j : g[u]) {  // 找所有與 u 相鄰的節點
      int v = j.first, w = j.second;
      if (!vis[v] && w < key[v]) {
        f[v] = u;
        key[v] = w;
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) ans += key[i];
  return ans;
}
