## 合併排序法

Defined in [merge_sort.cpp](/sort/merge_sort.cpp)

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

### 備註

-   陣列區間左閉右開 $[l, r)$
-   穩定的排序法
