## Finding Maximum Clique

-   團 Clique: 任選兩節點都有邊相連的圖
-   最大團 Maximum Clique: 一張圖的子圖中最大的團
-   獨立集 Independent Set: 一個圖中一些兩兩不相鄰的頂點所形成的集合
-   最大獨立集 Maximum Independent Set: 最大團的補集 (補圖)

### 用法

1. `init(n)` 初始化圖，其中 `n` 為節點點數
2. `addEdge(u, v)` 加入終點為 `u`, `v` 的無向邊
3. `solve()` 跑 MaxClique

### 結果

-   `solve()` 回傳回傳值為最大團的點數量  
    大獨立集裡

### 時間複雜度

$O({1.1888}^n)$
題目的 $n$ 通常最大可以到 $80$ ~ $100$ 左右

### 備註

-   這模板是 0-base
