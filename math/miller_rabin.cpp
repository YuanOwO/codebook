ll mul(ll x, ll y, ll mod) {
  ll ret = x * y - (ll)((long double)x / mod * y) * mod;
  return ret < 0 ? ret + mod : ret;
  // return x * y % mod; // for __int128
}

ll magic[] = {};  // 這邊填入要用於測試的數列
ll S = 3;         // 測試的數列數字的數量
bool witness(ll a, ll n, ll u, int t) {
  if (!a) return 0;
  ll x = power(a, u, n);
  for (int i = 0; i < t; i++) {
    ll nx = mul(x, x, n);
    if (nx == 1 && x != 1 && x != n - 1) return 1;
    x = nx;
  }
  return x != 1;
}
bool miller_rabin(ll n) {
  int s = S;  // magic number size
  // iterate s times of witness on n
  if (n < 2) return false;
  if (!(n & 1)) return (n == 2);

  // 將 n - 1 寫成 u * (2 ^ t) 的形式
  ll u = n - 1;
  int t = 0;
  while (!(u & 1))
    u >>= 1, t++;

  while (s--) {
    ll a = magic[s] % n;
    if (witness(a, n, u, t)) return false;
  }
  return true;
}
