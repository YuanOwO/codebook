/* 以上略 */
const int MXN = 2e5 + 5;
vector<int> g[MXN];
int n, k, mx_dep;
ll ans = 0;
bool vis[MXN];
int sz[MXN], cnt[MXN] = {1};

// 計算以 u 為根（忽略已移除的重心與父邊）的子樹大小
int get_sz(int u, int pre) {  // 這個先預處理
  sz[u] = 1;
  for (int& v : g[u]) {
    // 不跨越父親、也不進入已「移除當過重心」的節點
    if (v == pre || vis[v]) continue;
    sz[u] += get_sz(v, u);
  }
  return sz[u];
}

// 在包含 u 的當前子樹內找重心 :
// 從 u 出發，若存在子樹大小 >= desired (約 n/2)
// 就往那個子樹走
// 直到找不到更大的子樹為止，回傳當前節點作為重心
int get_cent(int u, int pre, int desired) {
  for (int& v : g[u]) {
    if (v != pre && sz[v] >= desired && !vis[v])
      return get_cent(v, u, desired);
  }
  return u;
}

void cal_cnt(int u, int pre, bool filling, int dep = 1) {
  if (dep > k) return;
  mx_dep = max(
      mx_dep,
      dep);  // 記錄本層最大深度，供稍後清空 cnt[] 使用
  if (filling)
    cnt[dep]++;  // 填表 :
                 // 把這個子樹的距離分布，併入「已處理過的子樹」
  else
    ans += cnt[k - dep];  // 查詢 : 找另一側距離是 (k -
                          // dep) 的節點數，配對成長度 k
  for (int& v : g[u]) {
    if (!vis[v] && pre != v)
      cal_cnt(v, u, filling, dep + 1);
  }
}

void decomp(int u = 1) {
  // 找重心 (若 total 偶數，可能落在任一個重心)
  int cent = get_cent(u, 0, get_sz(u, 0) / 2);

  vis[cent] = true;  // 移除重心，切割成多個子樹
  mx_dep = 0;        // 重置本層使用過的最大深度

  // 針對每個鄰接子樹 : 先查詢、後填表
  // (避免同一子樹內互相配對)
  for (int& v : g[cent]) {
    if (vis[v]) continue;
    cal_cnt(v, cent,
            false);  // 查詢 : 累加所有「經過重心」的長度=
                     // k 的路徑
    cal_cnt(
        v, cent,
        true);  // 填表 : 把這個子樹的距離分布併入 cnt[]
  }

  // 重置 cnt[] : 保留 cnt[0]=1
  // (代表僅重心)，清掉本層曾經動用過的深度範圍 註 :
  // 此實作選擇在「離開當前重心」時做清理，確保下一層剛進來時
  // cnt 狀態就是正確的
  cnt[0] = 1;
  for (int i = 1; i <= mx_dep; i++) cnt[i] = 0;

  // 遞迴處理每個子樹
  // (此時重心已被標記，不會跨越到其他分支)
  for (int& v : g[cent]) {
    if (!vis[v]) decomp(v);
  }
}
