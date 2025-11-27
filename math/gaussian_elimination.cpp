/**
 * mat[n][m] 為 n 個 m 元一次連例方程式的增廣矩陣
 * ans[m] 輸出 x_m 的解
 * pivot[n] 紀錄第 n 列的領導係數的位置
 * 若無解則回傳 false
 */
ll mat[MXN][MXN], ans[MXN];
int pivot[MXN];

/**
 * 回傳 true 代表有解，false 代表無解
 */
bool gaussian(int n, int m) {
  fill(pivot, pivot + m, -1);
  int row = 0;
  for (int col = 0; col < m && row < n; col++) {
    int sel = -1;
    for (int i = row; i < n;
         i++) {  // 找這一欄係數不為 0 的列
      if (mat[i][col] != 0) {
        sel = i;
        break;
      }
    }
    if (sel ==
        -1)  // 全是自由變數，直接跳過處理下一個變數
      continue;
    // 把找到的那一列換到當前 row 的位置
    for (int j = col; j <= m; j++)
      swap(mat[sel][j], mat[row][j]);

    // 歸一化：把主元 (mat[row][col]) 變成 1
    for (int j = col; j <= m; j++)
      mat[row][j] = mat[row][j] / mat[row][col];

    for (int i = 0; i < n; i++) {  // 消去
      if (i != row && mat[i][col] != 0) {
        ll factor = mat[i][col];
        for (int j = col; j <= m; j++)
          mat[i][j] = mat[i][j] - factor * mat[row][j];
      }
    }
    // 紀錄這個變數是由第 row 列解出來的
    // 處理下一列
    pivot[col] = row++;
  }
  // 檢查無解的情況
  // 剩下的列 (從 row 到 n-1)，左邊係數應該全被消成 0 了
  // 如果常數項 (mat[i][m]) 不為 0，表示 0 = k
  // (k!=0)，即無解
  for (int i = row; i < n; i++) {
    if (mat[i][m] != 0) return false;
  }
  for (int j = 0; j < m; j++) {  // 填入答案
    if (pivot[j] != -1)  // 對應的主元列的最右邊常數即為解
      ans[j] = mat[pivot[j]][m];
    else ans[j] = 0;
  }
  return true;
}
