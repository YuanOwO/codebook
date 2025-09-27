// isprime, 最大質因數, 質因數數量
int isPrime[MXN], fac[MXN], num[MXN];
void getPrimes() {
  isPrime[1] = 1, fac[1] = num[1];
  for (int i = 2; i < MXN; ++i) {
    if (isPrime[i]) continue;
    for (int j = i; j < MXN; j += i) {
      if (i != j) isPrime[j] = 1;
      fac[j] = i, num[j]++;
    }
  }
}
vector<int> ret;  // 質因數分解
void div(int x) {
  for (; x > 1; x /= fac[x]) ret.push_back(fac[x]);
}
