int min_rotation(string s) {
  int a = 0, N = s.size();
  s += s;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (a + j == i || s[a + j] < s[i + j]) {
        i += max(0, j - 1);
        break;
      }
      if (s[a + j] > s[i + j]) {
        a = i;
        break;
      }
    }
  }
  return a;
}
// rotate(begin(s),begin(s)+minRotation(s),end(s))
// 上面註解可以直接讓一個字串做 rotate ，得到字典序最小的
// rotation
