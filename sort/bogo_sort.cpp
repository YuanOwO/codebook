#include <algorithm>
#include <cstdlib>
#include <ctime>

template <typename T>
void shuffle(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        std::swap(arr[i], arr[j]);
    }
}

template <typename T>
void bogo_sort(T arr[], int n) {
    srand(time(NULL));
    bool is_sorted = 0;
    while (!is_sorted) {
        shuffle(arr, n);  // 洗牌
        for (int i = 1; i < n; i++)
            if (arr[i - 1] > arr[i])  // 不是遞增 -> 重新洗牌
                continue;
        is_sorted = 1;
    }
}
