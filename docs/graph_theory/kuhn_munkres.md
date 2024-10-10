## Kuhn–Munkres Algorithm

找二分圖最大權完美匹配

### 用法

1. `init(n)`: `n` 個節點初始化
2. `addEdge(u, v, w)`: 加邊 `u` -> `v`, 權重: `w`
3. 呼叫 `solve()`

### 結果

-   `my[i]`: 第 `i` 節點的匹配點

### 時間複雜度

$O(n^3)$

### 備註

-   1-base
