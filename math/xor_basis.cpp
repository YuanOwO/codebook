const int LOGN = 31;
vector<int> find_basis(vector<int>& arr) {
  vector<int> basis(LOGN);
  for (int& x : arr) {
    for (int i = LOGN - 1; i >= 0; i--) {
      if ((x & (1 << i)) == 0) continue;
      if (!basis[i]) {
        basis[i] = x;
        break;
      } else x ^= basis[i];
    }
  }
  return basis;
}
bool check(int x) {
  for (int i = LOGN; i >= 0; i--) {
    if (x & (1 << i)) {
      if (!basis[i]) return false;
      x ^= basis[i];
    }
  }
  return true;
}
