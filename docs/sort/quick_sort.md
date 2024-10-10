## 快速排序法

Defined in [quick_sort.cpp](/sort/quick_sort.cpp)

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

### 備註

-   陣列區間左閉右開 $[l, r)$
-   不穩定的排序法
