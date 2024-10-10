## Pollard's rho Algorithm

### 用法

呼叫 `fact(n)`

### 結果

`ret` 存入 `n` 的所有質因數

### 時間複雜度

pollard_rho: $O(n^{\frac{1}{4}})$

### 備註

-   `ret` 需排序
-   `n` 是質數時不能用，建議搭配 Miller-Rabin
