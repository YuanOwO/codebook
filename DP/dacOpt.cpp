// 使用條件：不依賴同層資訊+決策點有單調性+成本函數與分治不衝突
void solve(int k, int l=1, int r=n, int vl=1, int vr=n){
    if(l > r) return;
    int mid = (l + r) >> 1, p = 0;
    dp[k][mid] = 1e18;
    for(int i = vl; i <= min(vr, mid - 1); i ++){
        if(dp[k][mid] >= dp[k - 1][i] + f(i,j)){ //窮舉最佳轉移點
            dp[k][mid] = dp[k - 1][i] + f(i,j);
            p = i;
        }
    }
    solve(k, l, mid - 1, vl, p); // dp[i][1~mid-1] 的轉移點會在區間 vl~p 之間
    solve(k, mid + 1, r, p, vr); // dp[i][mid+1~r] 的轉移點會在區間 p~vr 之間
}
solve(k, k, n, 1, n);