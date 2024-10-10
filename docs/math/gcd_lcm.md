## 最大公因數

Defined in [gcd_lcm.cpp](/math/gcd_lcm.cpp)

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

Defined in [gcd_lcm.cpp](/math/gcd_lcm.cpp)

```cpp
ll lcm(ll a, ll b);
```

### 參數

-   `a`: 第一個正整數 $a$
-   `b`: 第二個正整數 $b$

### 回傳值

`ll`: $a$ 和 $b$ 的最小公倍數

### 備註

-   $lcm(a, b) = gcd(a, b) \cdot ab$
-   C++17 後新增 `std::lcm()` 函數
