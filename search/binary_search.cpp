/**
 * @brief 二分搜尋法
 * 時間複雜度 O(log N)
 *
 * @tparam T 陣列中元素的型別
 * @param arr 要搜尋的陣列，且已由小至大排序完成
 * @param n 陣列的大小
 * @param target 欲搜尋的目標
 * @return int 找到的目標索引值，如果找不到就回傳 -1
 */
template <typename T>
int binary_search(T arr[], int n, T target) {
    int l = 0, r = n - 1;  // 搜尋 [l, r] 區間
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == target)
            return m;
        else if (arr[m] < target)
            l = m + 1;
        else  // arr[m] > target
            r = m - 1;
    }
    return -1;  // 找不到
}
