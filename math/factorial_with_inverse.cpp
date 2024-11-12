ll fac[MXN], inv[MXN];
void init() {
  fac[0] = 1;  // 0! = 1
  for (ll i = 1; i < MXN; i++)
    fac[i] = fac[i - 1] * i % MOD;  // n! = n * (n-1)!
  inv[MXN - 1] = power(fac[MXN - 1], MOD - 2);
  for (ll i = MXN - 2; i >= 0; i--)
    inv[i] = inv[i + 1] * (i + 1) % MOD;  // (n!)^(-1)
}
