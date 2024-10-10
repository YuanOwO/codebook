## Tarjan's Algorithm for searching BCC

雙連通分量 Biconnected Component:  
不會產生割點使圖被分割成兩個不連通的子圖

### 用法

1. `init(n)` 初始化圖，其中 `n` 為節點點數
2. `addEdge(u, v)` 加入終點為 `u`, `v` 的無向邊
3. `solve()` 跑 BCC 回傳二維 `vector`

### 結果

回傳的二維 vector 中

-   一維 vector 是橋 if `size = 2`
-   一維 vector 是 BCC if `size > 2`
