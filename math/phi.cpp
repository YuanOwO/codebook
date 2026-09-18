int _phi(int n) {  // O(sqrtN)
  int res = n, a = n;
  for (int i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      res = res / i * (i - 1);
      while (a % i == 0) a /= i;
    }
  }
  if (a > 1) res = res / a * (a - 1);
  return res;
}

int phi[MXN]; // 線性篩打表
void phi_table(int n) {
  is_prime[0] = is_prime[1] = false;
  phi[1] = 1;
  for(int i = 2; i <= n; ++i) {
    if(is_prime[i]) {
      primes.push_back(i);
      phi[i] = i - 1;
    }
    for(int p : primes){
      if(1LL*i*p > n) break; 
      is_prime[i * p] = false;
      if(i % p == 0) {
        phi[i * p] = phi[i] * p;
        break; 
      } else {
        phi[i * p] = phi[i] * (p - 1);
      }
    }
  }
}