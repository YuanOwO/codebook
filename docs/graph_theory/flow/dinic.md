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
