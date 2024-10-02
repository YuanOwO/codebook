# 圖論

-   [圖論](#圖論)
    -   [拓樸排序](#拓樸排序)
    -   [Tarjan's Algorithm for searching BCC](#tarjans-algorithm-for-searching-bcc)
    -   [Bellmen-Ford Algorithm](#bellmen-ford-algorithm)
    -   [Dijkstra's Algorithm](#dijkstras-algorithm)
    -   [Dinic's algorithm](#dinics-algorithm)
    -   [Dominator Tree](#dominator-tree)
    -   [Floyd-Warshall Algorithm](#floyd-warshall-algorithm)
    -   [Finding Maximum Clique](#finding-maximum-clique)
    -   [Kosaraju's Algorithm for searching SCC](#kosarajus-algorithm-for-searching-scc)

## 拓樸排序

### 用法

1.  存好邊與 `deg`
2.  `topo()` 跑圖

### 結果

存在 `ans`

### 備註

-   處理有向無環圖 DAG
-   1-base

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

## Bellmen-Ford Algorithm

用每一條邊
找單源最短路徑

### 用法: 呼叫 bellmen_ford(n, m) 其中 n 為節點數 m 為邊數

### 結果: dis[i]: 從起點到 i 的最短路徑長

### 備註:

-   注意資料型態
-   一般來說，沒負環的話跑 `n - 1` 次就好
    如果跑到第 `n` 次仍鬆弛的到東西，那就是有負環

### 複雜度

$O(VE)$，其中 $E$ 是邊數，$V$ 是節點數

## Dijkstra's Algorithm

找單源最短路徑

### 用法

呼叫 `dijkstra(s)` 其中 `s` 為起點

### 結果

回傳 `dis[i]`: 從 `s` 到 `i` 的最短路徑長

### 備註

-   注意資料型態
-   `vec` 與 `pq` 存的資料是反的喔
-   邊權不可以有負的

### 複雜度

$O(E + E \cdot \log V)$，其中 $E$ 是邊數、$V$ 是節點數

## Dinic's algorithm

Finding maximum flow

### 用法

1.  初始化 `init(_n, _s, _t)`  
    其中 `_n` 是節點數、`_s` 是源點、`_t` 是匯點
2.  `add_edge(u, v, f)` 加入邊  
    其中 `u` 起點 `v` 終點 `f` 流量
3.  `flow()` 回傳最大流量答案

### 結果

算出圖的最大流量

### 備註

-   注意資料型態 (如果要用 `long long`)
-   圖必須是 0-base
-   圖是有向圖

## Dominator Tree

支配點: 走到某節點的必經節點

### 用法:

1. `init(n, s)` 初始化，其中 `n` 為節點數量 `s` 為起點編號
2. `addEdge(u, v)` 加入 `u` $\rightarrow$ `v` 的有向邊
3. `build()` 跑 Dominator Tree

### 結果:

-   `idom[i]`: 節點 `i` 的支配點

### 備註:

-   有向圖
-   可以用回朔法找到整顆支配樹

### 時間複雜度

$O(n + m)$

## Floyd-Warshall Algorithm

全圖最短路徑  
圖上找任兩點都有最短路徑長

### 用法

1. `init(n)` 初始化 其中 `n` 為節點數
2. 輸入 `dis[u][v]`: 從 `u` 到 `v` 的原始距離
3. 呼叫 `floyd_warshall(n)` 算答案

### 結果

`dis[u][v]`: 從 `u` 到 `v` 的最短路徑長

### 備註

-   注意資料型態
-   如果有負環 `dis[u][u]` 會小於 $0$
-   `n = 1000` 仍可以在 $1$ 秒內跑完 (應該啦)

### 複雜度

$O(n^3)$， 其中 $n$ 是節點數

## Finding Maximum Clique

-   團 Clique: 任選兩節點都有邊相連的圖
-   最大團 Maximum Clique: 一張圖的子圖中最大的團
-   獨立集 Independent Set: 一個圖中一些兩兩不相鄰的頂點所形成的集合
-   最大獨立集 Maximum Independent Set: 最大團的補集 (補圖)

### 用法:

1. `init(n)` 初始化圖，其中 `n` 為節點點數
2. `addEdge(u, v)` 加入終點為 `u`, `v` 的無向邊
3. `solve()` 跑 MaxClique

### 結果:

-   `solve()` 回傳回傳值為最大團的點數量  
    大獨立集裡

### 備註:

-   這模板是 0-base

### 複雜度

$O({1.1888}^n)$
題目的 $n$ 通常最大可以到 $80$ ~ $100$ 左右

## Kosaraju's Algorithm for searching SCC

強連通分量 Strongly Connected Components:  
圖中任兩點 `u`, `v` 必包含`u` $\rightarrow$ `v` 和 `v` $\rightarrow$ `u` 的路徑

### 用法:

1. `init(n)` 初始化圖 其中 `n` 為節點點數
2. `addEdge(u, v)` 加入 `u` $\rightarrow$ `v` 的有向邊
3. `solve()` 跑 SCC

### 結果:

-   `bln[i]`: 第 `i` 個節點屬於的 `SCC` 編號為 `bln[i]`
-   `nScc`: 強連通分量 SCC 數量

### 複雜度

$O(n + m)$，其中 $n$: 節點數、$m$: 邊數
