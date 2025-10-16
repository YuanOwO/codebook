vector<ll> ret;
ll f(ll x, ll c, ll mod) {
  return (mul(x, x, mod) + c) % mod;
}
ll pollard_rho(ll n) {
  ll c = 1, x = 0, y = 0, p = 2, q, t = 0;
  while (t++ % 128 || gcd(p, n) == 1) {
    if (x == y) c++, y = f(x = 2, c, n);
    if (q = mul(p, abs(x - y), n)) p = q;
    x = f(x, c, n);
    y = f(f(y, c, n), c, n);
  }
  return gcd(p, n);
}
void fact(ll x) {  // 透過遞迴找質數
  if (miller_rabin(x)) {
    ret.push_back(x);
    return;
  }
  ll f = pollard_rho(x);
  fact(f);
  fact(x / f);
}
