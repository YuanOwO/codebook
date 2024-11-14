const int LG_MXN = __lg(MXN) + 2;
vector<int> edge[MXN];  // i 有哪些小孩
int timing = 1, lgN, n;
int in[MXN], out[MXN], anc[MXN][LG_MXN], depth[MXN];
void dfs_init(int u, int f) {  // 0 倍祖先、時間戳記
  in[u] = timing++;            // 這時進入 u
  anc[u][0] = f;               // now 的 0 倍祖先是 f
  for (int v : edge[u]) {
    if (v == f) continue;
    depth[v] = depth[u] + 1;
    dfs_init(v, u);
  }
  out[u] = timing++;  // 這時離開 u
}
void build_table(int n) {  // 初始化
  lgN = __lg(n) + 1;
  dfs_init(1, 0);
  for (int i = 1; i <= lgN; i++)  // 建立倍增表
    for (int now = 1; now <= n; now++)
      anc[now][i] = anc[anc[now][i - 1]][i - 1];
}
