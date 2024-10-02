# 排序演算法

-   [排序演算法](#排序演算法)
-   [穩定的排序法](#穩定的排序法)
    -   [氣泡排序法](#氣泡排序法)
    -   [合併排序法](#合併排序法)
-   [不穩定的排序法](#不穩定的排序法)
    -   [選擇排序法](#選擇排序法)
    -   [快速排序法](#快速排序法)
-   [不實用的排序法](#不實用的排序法)
    -   [Bogo 排序法](#bogo-排序法)
-   [附錄](#附錄)

# 穩定的排序法

## 氣泡排序法

Defined in [bubble_sort.cpp](./bubble_sort.cpp)

```cpp
template <typename T>
void bubble_sort(T arr[], int n);
```

### 參數

-   `T`: 可以比較大小的類別
-   `arr`: 欲排序的陣列
-   `n`: 陣列的大小

### 時間複雜度

-   Average: $O(n^2)$
-   Worst: $O(n^2)$
-   Best: $O(n)$

### Note

-   穩定的排序法

## 合併排序法

Defined in [merge_sort.cpp](./merge_sort.cpp)

```cpp
template <typename T>
void merge_sort(T arr, T tmp, int l, int r);
```

### 參數

-   `T`: 可以比較大小的類別
-   `arr`: 欲排序的陣列
-   `tmp`: 用來暫存結果的陣列
-   `l`: 陣列的左邊 (包含)
-   `r`: 陣列的右邊 (不包含)

### 時間複雜度

-   Average: $O(n \log n)$
-   Worst: $O(n \log n)$
-   Best: $O(n \log n)$

### 空間複雜度

-   額外空間 $O(n)$

### Note

-   陣列區間左閉右開 $[l, r)$
-   穩定的排序法

# 不穩定的排序法

## 選擇排序法

Defined in [selection_sort.cpp](./selection_sort.cpp)

```cpp
template <typename T>
void selection_sort(T arr[], int n);
```

### 參數

-   `T`: 可以比較大小的類別
-   `arr`: 欲排序的陣列
-   `n`: 陣列的大小

### 時間複雜度

-   Average: $O(n^2)$
-   Worst: $O(n^2)$
-   Best: $O(n^2)$

### Note

-   不穩定的排序法

## 快速排序法

Defined in [quick_sort.cpp](./quick_sort.cpp)

```cpp
template <typename T>
void quick_sort(T arr[], int l, int r);
```

### 參數

-   `T`: 可以比較大小的類別
-   `arr`: 欲排序的陣列
-   `l`: 陣列的左邊 (包含)
-   `r`: 陣列的右邊 (不包含)

### 時間複雜度

-   Average: $O(n \log n)$
-   Worst: $O(n^2)$
-   Best: $O(n \log n)$

### Note

-   陣列區間左閉右開 $[l, r)$
-   不穩定的排序法

# 不實用的排序法

## Bogo 排序法

Defined in [bogo_sort.cpp](./bogo_sort.cpp)

```cpp
void bogo_sort(T arr[], int n);
```

### 參數

-   `T`: 可以比較大小的類別
-   `arr`: 欲排序的陣列
-   `n`: 陣列的大小

### 時間複雜度

-   Average: $O(n \cdot n!)$
-   Worst: $O(\infty)$
-   Best: $O(n)$

### Note

-   不穩定的排序法
-   不實用的排序法

# 附錄

根據 [@ShanC](https://github.com/ShanCisgood) 的描述，排序演算法的複雜度只少為 $O(n \log n)$ 以上，其詳細證明請參見他的筆記本。
