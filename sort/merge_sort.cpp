/**
 * @brief 合併排序法
 * 時間複雜度 O(N log N)
 * 陣列區間 [l, r)
 *
 * @tparam T 可以比較大小的型別
 * @param arr 欲排序的陣列
 * @param tmp 用來暫存結果的陣列
 * @param l 陣列的左邊 (包含)
 * @param r 陣列的右邊 (不包含)
 */
template <typename T>
void merge_sort(T arr, T tmp, int l, int r) {
    // 陣列元素少於 1 直接結束
    if (r <= l + 1)
        return;

    // 分成左右兩邊處理
    int m = l + (r - l) / 2;
    merge_sort(arr, tmp, l, m);  // [l, m)
    merge_sort(arr, tmp, m, r);  // [m, r)

    // 合併兩邊的結果
    for (int i = l, li = l, ri = m; i < r; i++) {
        // 只剩下右邊 || 兩邊都有剩，右邊比左邊小
        if (li == m || (ri != r && arr[ri] < arr[li]))
            tmp[i] = arr[ri++];
        // 只剩下左邊 || 兩邊都有剩，左邊比右邊小
        else
            tmp[i] = arr[li++];
    }

    // 把結果複製回來
    for (int i = l; i < r; i++)
        arr[i] = tmp[i];
}
