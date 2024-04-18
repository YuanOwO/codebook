#include <algorithm>

using namespace std;

const int MXN = 2e6 + 5;

int main() {
    int arr[MXN], tmp[MXN];
    int n;
    // arr[i] 是初始陣列, 長度為n, 且 0-base
    for (int i = 0; i < n; i++)  // 將 arr 複製到 tmp
        tmp[i] = arr[i];
    sort(tmp, tmp + n);                      // 排序
    int len = unique(tmp, tmp + n) - (tmp);  // 把 tmp 裡重複的數字去掉
    for (int i = 0; i < n; i++)
        arr[i] = lower_bound(tmp, tmp + len, arr[i]) - tmp;  // 二分搜
    return 0;
}
