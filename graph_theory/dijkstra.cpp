vector<pii> vec[N];  // vec[u] = {v, w}: u 為起點 v 為終點
                     // w 為路權
bool vis[N];                   // 紀錄該節點是否走過
vector<int> dijkstra(int s) {  // 起點
  vector<int> dis(N);
  for (int i = 0; i < N; i++)  // 初始化
    dis[i] =
        INF;  // 值要設為比可能的最短路徑權重還要大的值
  dis[s] = 0;
  priority_queue<pii, vector<pii>, greater<pii>>
      pq;  // 以小到大排序
  // {w, v}: w 為路權 v 為節點
  pq.push({dis[s], s});
  while (pq.empty() == 0) {
    int u = pq.top().second;
    pq.pop();
    if (vis[u])  // 走過的不要再走
      continue;
    vis[u] = 1;
    for (auto i : vec[u]) {
      int v = i.first, w = i.second;
      if (dis[u] + w < dis[v]) {  // 鬆弛
        dis[v] = dis[u] + w;
        pq.push({dis[v], v});
      }
    }
  }
  return dis;
}
