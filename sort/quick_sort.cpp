/**
 * @brief 快速排序法
 * 時間複雜度 O(N log N)
 * 陣列區間 [l, r)
 *
 * @tparam T 可以比較大小的型別
 * @param arr 欲排序的陣列
 * @param l 陣列的左邊 (包含)
 * @param r 陣列的右邊 (不包含)
 */
template <typename T>
void quick_sort(T arr[], int l, int r) {
    // 陣列元素少於 1 直接結束
    if (r <= l + 1)
        return;

    // 左邊和右邊的指針
    int li = l + 1, ri = r - 1;
    // 判定的基準點
    T pivot = arr[l];

    // TODO: 左邊 <= 基準點 < 右邊
    while (li != ri) {
        // 右邊的指針往左移動，找比基準點小的值
        while (arr[ri] > pivot && li < ri)
            ri--;
        // 左邊的指針往右移動，找比基準點大的值
        while (arr[li] <= pivot && li < ri)
            li++;
        // 當左右指針沒有相遇時，表示不滿足 TODO
        if (li < ri)
            swap(arr[li], arr[ri]);
    }

    // 將基準點移到指針相遇的地方
    arr[l] = arr[li];
    arr[li] = pivot;

    quick_sort(arr, l, li);      // 處理基準點的左邊
    quick_sort(arr, li + 1, r);  // 處理基準點的右邊
}
