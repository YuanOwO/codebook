/**
 * mat[n][m] 為 n 個 m 元一次連例方程式的增廣矩陣
 * ans[m] 輸出 x_m 的解
 * led[n] 紀錄第 n 列的領導係數的位置
 * 若無解則回傳 false
 */
ll mat[MXN][MXN], ans[MXN], led[MXN];
bool gaussian(int n, int m) {
  for (int i = 0; i < n; i++) {  // 高斯消元法
    // 第 i 列的領導項
    while (led[i] <= m && mat[i][led[i]] == 0) led[i]++;
    // 當每項係數皆為 0 時，mat_{im} == b_i != 0 => 無解
    if (led[i] == m && mat[i][m] != 0) return false;
    int c = led[i];
    for (int j = 0; j < n; j++) {
      // 消掉第 j 列的這項係數，使 mat_{jc} = 0
      if (i == j) continue;
      int r = mat[j][c] / mat[i][c];
      // mat_j -= mat_i * (mat_{jc} / mat_{ic})
      for (int k = c; k <= m; k++)
        mat[j][k] = mat[j][k] - mat[i][k] * r;
    }
  }
  for (int i = 0; i < m; i++) {
    // 紀錄 x_c 的解為 b_i / mat_{ic}
    ans[led[i]] = mat[i][m] / mat[i][led[i]];
  }
  return true;  // 有解
}
