vector<int> num;
int dp[20][state];
int dfs(int pos, int state, bool lead, bool limit) {
  if (pos == num.size()) {  // 有時要根據不同state回傳情況
    return 1;
  }
  if (limit == false && lead == false &&
      dp[pos][state] != -1)
    return dp[pos][state];
  int up = limit ? num[pos] : 9;
  int ans = 0;
  for (int i = 0; i <= up; i++) {
    // 有時要考慮那些狀況要continue
    ans += dfs(pos + 1, state || (check[i] == 2),
               lead && i == 0, limit && i == num[pos]);
  }
  if (limit == false && lead == false)
    dp[pos][state] = ans;
  return ans;
}
