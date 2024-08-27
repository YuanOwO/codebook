/**
 * @brief 快速傅立葉變換 FFT
 *
 * 功能: 求兩多項式相乘的係數
 * 用法:
 * 1. 不管要幹嘛 先跑 pre_fft()
 * 2. 把兩陣列與長度塞入 mul()
 *    其中 a[i]: 第一個多項式 x^i 項係數, n 為其長度
 *         b[i]: 第二個多項式 x^i 項係數, m 為其長度
 *         ans[i]: 答案的多項式 x^i 項係數
 *
 * 備註: MAXN 一定要是 2 的冪次
 *      我不會工數所以我也不清楚細節 BY SHANC
 *
 */

#define ll long long
const int MAXN = 262144 << 1;
// (must be 2^k)
// before any usage, run pre_fft() first
typedef long double ld;
typedef complex<ld> cplx;  // real(), imag()
const ld PI = acosl(-1);
const cplx I(0, 1);
cplx omega[MAXN + 1];
void pre_fft() {
    for (int i = 0; i <= MAXN; i++)
        omega[i] = exp(i * 2 * PI / MAXN * I);
}
// n must be 2^k
void fft(int n, cplx a[], bool inv = false) {
    int basic = MAXN / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; i++) {
            cplx w = omega[inv ? MAXN - (i * theta % MAXN)
                               : i * theta % MAXN];
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                cplx x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta = (theta * 2) % MAXN;
    }
    int i = 0;
    for (int j = 1; j < n - 1; j++) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1)
            ;
        if (j < i)
            swap(a[i], a[j]);
    }
    if (inv)
        for (i = 0; i < n; i++)
            a[i] /= n;
}
cplx arr[MAXN + 1];
inline void mul(int _n, ll a[], int _m, ll b[], ll ans[]) {
    int n = 1, sum = _n + _m - 1;
    while (n < sum)
        n <<= 1;
    for (int i = 0; i < n; i++) {
        double x = (i < _n ? a[i] : 0), y = (i < _m ? b[i] : 0);
        arr[i] = complex<double>(x + y, x - y);
    }
    fft(n, arr);
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];
    fft(n, arr, true);
    for (int i = 0; i < sum; i++)
        ans[i] = (long long int)(arr[i].real() / 4 + 0.5);
}
