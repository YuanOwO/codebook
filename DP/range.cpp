// 區間大小為 1 為 base case
for (int i = 1; i <= n; i++) dp[i][i] = 0;
// 由小區間往大開始轉移
for (int len = 2; len <= n; len++)
  for (int l = 1, r = len; r <= n; l++, r++) {
    dp[l][r] = INF;
    for (int k = l; k < r; k++)
      dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] +
                                   n[i] * m[k] * n[r]);
  }
return dp[1][n];
