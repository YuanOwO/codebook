ll power(ll x, ll y) {
  ll ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % MOD;
    x = x * x % MOD, y >>= 1;
  }
  return ret;
}
