void calcH(ll &t, ll &h, const ll p) {
  ll tmp = p - 1;
  for (t = 0; (tmp & 1) == 0; tmp /= 2)
    t++;
  h = tmp;
}
// solve equation x^2 mod p = a
bool solve(ll a, ll p, ll &x, ll &y) {
  if (p == 2) {
    x = y = 1;
    return true;
  }
  int p2 = p / 2, tmp = power(a, p2, p);
  if (tmp == p - 1) return false;
  if ((p + 1) % 4 == 0) {
    x = power(a, (p + 1) / 4, p);
    y = p - x;
    return true;
  } else {
    ll t, h, b, pb;
    calcH(t, h, p);
    if (t >= 2) {
      do {
        b = rand() % (p - 2) + 2;
      } while (power(b, p / 2, p) != p - 1);
      pb = power(b, h, p);
    }
    int s = power(a, h / 2, p);
    for (int step = 2; step <= t; step++) {
      int ss = (((ll)(s * s) % p) * a) % p;
      for (int i = 0; i < t - step; i++)
        ss = mul(ss, ss, p);
      if (ss + 1 == p) s = (s * pb) % p;
      pb = ((ll)pb * pb) % p;
    }
    x = ((ll)s * a) % p;
    y = p - x;
  }
  return true;
}
