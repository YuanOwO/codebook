struct Mat {  // Mat t(r, c);
  ll a[200][200], r, c;
  Mat(int _r, int _c) : r(_r), c(_c) {
    memset(a, 0, sizeof(a));
  }
  void build() {  // 單位矩陣
    for (int i = 0; i < r; ++i) a[i][i] = 1;
  }
};
Mat operator*(Mat x, Mat y) {
  Mat z(x.r, y.c);
  for (int i = 0; i < x.r; ++i)
    for (int j = 0; j < x.c; ++j)
      for (int k = 0; k < y.c; ++k)
        (z.a[i][j] += x.a[i][k] * y.a[k][j] % MOD) %= MOD;
  return z;
}
