## Dominator Tree

支配點: 走到某節點的必經節點

### 用法

1. `init(n, s)` 初始化，其中 `n` 為節點數量 `s` 為起點編號
2. `addEdge(u, v)` 加入 `u` $\rightarrow$ `v` 的有向邊
3. `build()` 跑 Dominator Tree

### 結果

-   `idom[i]`: 節點 `i` 的支配點

### 時間複雜度

$O(n + m)$

### 備註

-   有向圖
-   可以用回朔法找到整顆支配樹
