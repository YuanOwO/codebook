struct BIT {
  int n, bit[MXN][MXN];
  int lowbit(int x) { return x & -x; }
  BIT(int _n) : n(_n + 1) { memset(bit, 0, sizeof(bit)); }
  void update(int x, int y, int val) {  // 更新 (x, y)
    for (; x < n; x += lowbit(x))
      for (; y < n; y += lowbit(y)) bit[x][y] += val;
  }
  int query(int x, int y) {  // 查詢 (1, 1) ~ (x, y) 的和
    int ans = 0;
    for (; x; x -= lowbit(x))
      for (; y; y -= lowbit(y)) ans += bit[x][y];
    return ans;
  }
  int range_query(int a, int b, int x, int y) {
    return query(x, y) - query(x, b - 1) - query(a - 1, y) +
           query(a - 1, b - 1);
  }
} bit;
