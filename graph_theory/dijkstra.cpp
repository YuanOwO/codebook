#define pii pair<int, int>
#define INF 1e18
const int N = 2e5 + 5;

/**
 * @brief Dijkstra's Algorithm
 * 找單源最短路徑
 *
 * 用法: 呼叫 dijkstra(s) 其中 s 為起點
 * 結果: 回傳 dis[i]: 從 s 到 i 的最短路徑長
 * 備註:
 * - 注意資料型態
 * - vec 與 pq 存的資料是反的喔
 *
 * 複雜度: O(E + E * logV) 其中 E 是 邊數 V 是節點
 */

vector<pii> vec[N];  // vec[u] = {v, w}: u 為起點 v 為終點 w 為路權
bool vis[N];         // 紀錄該節點是否走過
vector<int> dijkstra(int s) {  // 起點
    vector<int> dis(N);
    for (int i = 0; i < N; i++)  // 初始化
        dis[i] = INF;  // 值要設為比可能的最短路徑權重還要大的值
    dis[s] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // 以小到大排序
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
