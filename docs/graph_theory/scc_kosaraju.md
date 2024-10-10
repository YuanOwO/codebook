## Kosaraju's Algorithm for searching SCC

強連通分量 Strongly Connected Components:  
圖中任兩點 `u`, `v` 必包含`u` $\rightarrow$ `v` 和 `v` $\rightarrow$ `u` 的路徑

### 用法

1. `init(n)` 初始化圖 其中 `n` 為節點點數
2. `addEdge(u, v)` 加入 `u` $\rightarrow$ `v` 的有向邊
3. `solve()` 跑 SCC

### 結果

-   `bln[i]`: 第 `i` 個節點屬於的 `SCC` 編號為 `bln[i]`
-   `nScc`: 強連通分量 SCC 數量

### 時間複雜度

$O(n + m)$，其中 $n$: 節點數、$m$: 邊數
