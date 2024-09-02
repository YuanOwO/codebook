template <typename T>
void bubble_sort(T arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)          // [0, n)
        for (j = 0; j < n - 1 - i; j++)  // [0, n-i)
            // 比較大的往後移
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}
