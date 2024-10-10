## 拓展歐基里德法 (EXGCD)

Defined in [exgcd.cpp](/math/exgcd.cpp)

```cpp
int exgcd(int a, int b, ll &x, ll &y);
```

### 用途

除了求出最大公因數之外，還幫你找到 $ax + by = gcd(a, b)$ 的一組整數解

### 參數

-   `a`: $a$
-   `b`: $b$
-   `x`: $x$
-   `y`: $y$

### 回傳值

`int`: $a$ 和 $b$ 的最大公因數

### 備註

`x` 和 `y` 是指標喔！之後得到的一組解會存在裡面。
