const int M = 1e9 + 7;
const int C = 13331;
struct HashString { // 1-base
  int n;
  vector<ll> pows, sums;
  HashString(string s)
      : n(s.size()), pows(n + 1, 1), sums(n + 1) {
    for (int i = 1; i <= n; i++) {
      pows[i] = pows[i - 1] * C % M;
      sums[i] = (sums[i - 1] * C + s[i - 1]) % M;
    }
  }
  // Returns the hash of the substring (l, r]
  ll hash(int l, int r) {
    ll h = sums[r] - sums[l] * pows[r - l];
    return (h % M + M) % M;
  }
};
