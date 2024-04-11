/**
 * @brief 搜尋
 * 時間複雜度 O(N)
 *
 * @tparam T 陣列中元素的型別
 * @param arr 要搜尋的陣列
 * @param n 陣列的大小
 * @param target 欲搜尋的目標
 * @return int 找到的目標索引值，如果找不到就回傳 -1
 */
template <typename T>
int binary_search(T arr[], int n, T target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target)
            return i;
    return -1;  // 找不到
}
