const int MAXN = 1e3 + 5;

struct Edge {
    int from, to, weight;
} edge[MAXN];

/**
 * @brief Bellmen-Ford Algorithm
 * 用每一條邊
 * 找單源最短路徑
 *
 * 用法: 呼叫 bellmen_ford(n, m) 其中 n 為節點數 m 為邊數
 * 結果: dis[i]: 從起點到 i 的最短路徑長
 * 備註:
 * - 注意資料型態
 * - 一般來說 沒負環的話跑 n - 1 次就好
 * - 如果跑到第 n 次仍鬆弛的到東西 那就是有負環
 *
 * 複雜度: O(VE) 其中 E 是 邊數 V 是節點
 */

int dis[MAXN];
void bellmen_ford(int n, int m) {
    dis[1] = 0;                        // 起點的距離一定是 0
    for (int j = 0; j < n - 1; j++) {  // n 個節點要跑 n - 1 次
        for (int i = 0; i < m; i++) {  // 對於所有邊都嘗試鬆弛
            if (dis[edge[i].to] > dis[edge[i].from] + edge[i].weight)
                dis[edge[i].to] = dis[edge[i].from] + edge[i].weight;
        }
    }
}
