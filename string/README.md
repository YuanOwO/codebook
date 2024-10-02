# 字串演算法

-   [字串演算法](#字串演算法)
    -   [Knuth–Morris–Pratt Algorithm](#knuthmorrispratt-algorithm)
    -   [Manacher's Algorithm](#manachers-algorithm)
    -   [Minimum Rotation](#minimum-rotation)
    -   [Rolling Hash Method](#rolling-hash-method)

## Knuth–Morris–Pratt Algorithm

### 用途

比較字串

### 用法

傳入兩字串 `t` 與 `p`

### 結果

回傳答案 `ret`

### 備註

-   `ret`: `p` 出現在 `t` 的位置
-   ShanC 不太會用

## Manacher's Algorithm

### 用途

找最常迴文

### 用法

呼叫 `z_value_pal(s, len, z)`  
其中 `s` 為輸入字串 `len` 為長度 `z` 為輸出陣列

### 結果

`ret` 即為最長迴文

### 備註

-   陣列要開兩倍大
-   ShanC 忘記怎麼用

## Minimum Rotation

### 用途

Rotation: 把字元從頭丟到尾巴

### 用法

`min_rotation(s)` 其中 `s` 為要處理的字串

### 結果

得一整數為最小 rotation 數

### 備註

-   那一行註解很好用

## Rolling Hash Method

### 用途

~~暴力的~~比較字串

### 用法

把要弄的字串跟 `hashs[]` 丟入 `build()`

### 備註

-   這裡亂亂的
-   ~~可以自備一些喜歡的質數~~
