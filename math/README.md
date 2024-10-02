# 數學與算術方法

-   [數學與算術方法](#數學與算術方法)
-   [數論](#數論)
    -   [factorial and it's modular inverse 與 排列組合 shit](#factorial-and-its-modular-inverse-與-排列組合-shit)
    -   [最大公因數](#最大公因數)
    -   [最小公倍數](#最小公倍數)
    -   [EXGCD 拓展歐基里德法](#exgcd-拓展歐基里德法)
-   [算術](#算術)
    -   [快速冪取模](#快速冪取模)
-   [演算法](#演算法)
    -   [快速傅立葉變換 FFT](#快速傅立葉變換-fft)
    -   [Miller-Rabin test for prime test](#miller-rabin-test-for-prime-test)
    -   [Pollard's rho Algorithm](#pollards-rho-algorithm)

# 數論

## factorial and it's modular inverse 與 排列組合 shit

### 用法

1.  呼叫 `init()` 初始化
2.  視情況呼叫 `comb()`、`perm()` 或 `h()`

### 結果

1.  階乘及其模逆元會存在 `fac[]` 跟 `inv[]`
2.  `comb()`、`perm()` 或 `h()` 會算出結果

### 備註

-   注意數字大小不能超過 `MXN`

## 最大公因數

Defined in [gcd_lcm.cpp](./gcd_lcm.cpp)

```cpp
ll gcd(ll a, ll b);
```

### 參數

-   `a`: 第一個正整數 $a$
-   `b`: 第二個正整數 $b$

### 回傳值

`ll`: $a$ 和 $b$ 的最大公因數

### 備註

-   某些編譯器有提供 `__gcd(a, b)` 可以使用
-   C++17 後新增 `std::gcd()` 函數

## 最小公倍數

Defined in [gcd_lcm.cpp](./gcd_lcm.cpp)

```cpp
ll lcm(ll a, ll b);
```

### 參數

-   `a`: 第一個正整數 $a$
-   `b`: 第二個正整數 $b$

### 回傳值

`ll`: $a$ 和 $b$ 的最小公倍數

### 備註

-   $lcm(a, b) = gcd(a, b) \cdot a \cdot b$
-   C++17 後新增 `std::lcm()` 函數

## EXGCD 拓展歐基里德法

Defined in [exgcd.cpp](./exgcd.cpp)

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

`int`: `a` 和 `b` 的最大公因數

### 備註

`x` 和 `y` 是指標喔！之後得到的一組解會存在裡面。

# 算術

## 快速冪取模

Defined in [fast_pow.cpp](./fast_pow.cpp)

```cpp
ll power(ll x, ll y);
```

### 參數

-   `x`: 底數
-   `y`: 指數

### 回傳值

`ll`: $x^y \mod MOD$ 之值

### 備註

-   $MOD$ 要是一個質數

# 演算法

## 快速傅立葉變換 FFT

### 用途

求兩多項式相乘的係數

### 用法

1. 不管要幹嘛，先跑 `pre_fft()`
2. 把兩陣列與長度塞入 `mul()`，其中:
    - `a[i]`: 第一個多項式 $x^i$ 項係數, `n` 為其長度
    - `b[i]`: 第二個多項式 $x^i$ 項係數, `m` 為其長度
    - `ans[i]`: 答案的多項式 $x^i$ 項係數

### 備註

-   `MAXN` 一定要是 $2$ 的冪次
-   我不會工數所以我也不清楚細節 By ShanC

## Miller-Rabin test for prime test

### 判斷質數

### 用法

1. 挑選一處 `magic` 並填入陣列大小 `S`
2. 呼叫 `miller_rabin(n)`

### 結果

回傳 `n` 是否為質數

### 時間複雜度

$O(k \log^3 n)$

### 備註

1.  要確定要判斷的整數 `n` 是介於 $[2, n - 2]$
2.  測試數列 `magic` 如下:  
    $n < 4,759,123,141$, s = 3: {2, 7, 61}  
    $n < 1,122,004,669,633$, s = 4: {2, 13, 23, 1662803}  
    $n < 3,474,749,660,383$, s = 6: {2, 3, 5, 7, 13}  
    $n < 2^{64}$,  
    s = 7: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}

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
