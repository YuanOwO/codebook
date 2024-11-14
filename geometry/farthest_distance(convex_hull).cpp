double FarthestPair(vector<Pt> arr) {
  double ret = 0;  // 傳入凸包
  int sz = sz;
  for (int i = 0, j = i + 1; i < sz; i++) {
    while (distance(arr[i], arr[j]) <=
           distance(arr[i], arr[(j + 1) % sz])) {
      j = (j + 1) % sz;
    }
    ret = max(ret, distance(arr[i], arr[j]));
  }
  return ret;
}
