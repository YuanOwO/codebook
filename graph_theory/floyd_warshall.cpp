#define INF 1e9
const int N = 2e3 + 5;

/**
 * @brief Floyd-Warshall Algorithm
 * 全圖最短路徑
 * 圖上找任兩點都有最短路徑長
 *
 * 用法: 呼叫 floyd_warshall(n) 其中 n 為節點數
 * 結果: dis[u][v]: 從 u 到 v 的最短路徑長
 * 備註:
 * - 注意資料型態
 * - 如果有負環 dis[u][u] 會小於 0
 * - n = 1000 仍可以在 1s 內跑完 (應該啦)
 *
 * 複雜度: O(N^3) 其中 N 是節點數
 */

int dis[N][N];
void floyd_warshall(int n) {
    for (int i = 0; i <= n; i++) {  // 初始化
        for (int j = 0; j <= n; j++)
            dis[i][j] = INF;
        dis[i][i] = 0;
    }

    for (int k = 0; k < n; k++) {  // 窮舉中繼點 k
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {  // 窮舉點對 (i, j)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
