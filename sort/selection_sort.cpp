/**
 * @brief 選擇排序法
 * 時間複雜度 O(N^2)
 *
 * @tparam T 可以比較大小的型別
 * @param arr 欲排序的陣列
 * @param n 陣列的大小
 */
template <typename T>
void selection_sort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++)  // [0, n-1)
    {
        // 設未排序陣列中的第一個元素為最小的
        int m = i;
        for (int j = i + 1; j < n; j++)  // [i+1, n)
            // 找到未排序中最小元素的 index
            if (arr[m] > arr[j])
                m = j;

        // 將最小的數字放到已排序數列中的最後面
        swap(arr[i], arr[m]);
    }
}
