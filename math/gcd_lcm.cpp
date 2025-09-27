ll gcd(ll a, ll b) {
  if (b && a)  // 輾轉先除法 -> 交叉取餘數直到不能再取
    while ((a %= b) && (b %= a)) {}
  return a + b;
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
