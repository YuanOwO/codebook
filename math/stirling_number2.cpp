ll dp[MAXN][MAXN];
ll stirling_number2(int n, int k) {
  memset(dp, 0, sizeof(dp));
  dp[1][1] = 1;
  for (int i = 2; i <= n; i++) {  // Stirling number
    for (int j = 1; j <= i; j++)
      dp[i][j] =
          (dp[i - 1][j - 1] + j * dp[i - 1][j]) % MOD;
  }

  //   for (int i = 1; i <= k; i++)  // consider 順序
  //     dp[n][k] = dp[n][k] * i % MOD;

  return dp[n][k];
}
