int josephus(int n, int m) {  // n 人每 m 次
  int ans = 0;
  for (int i = 1; i <= n; ++i) ans = (ans + m) % i;
  return ans;
}
