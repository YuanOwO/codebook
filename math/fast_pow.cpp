ll power(ll x, ll y, ll mod) {
  ll ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % mod;
    x = x * x % mod, y >>= 1;
  }
  return ret;
}
