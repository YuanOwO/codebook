bool vis[MXN], Map[MXN][MXN];
int S[MXN];  // 其中 Map 為鄰接表, S 為紀錄這個點與誰匹配
int n, p;    // n: 左集合數量, p: 右集合數量
bool slove(int u) {
    for (int i = 1; i <= n; i++) {
        if (Map[u][i] && !vis[i]) {         // 有連通且未拜訪
            vis[i] = 1;                     // 紀錄是否走過
            if (S[i] == -1 || dfs(S[i])) {  // 紀錄匹配
                S[i] = u;
                return true;  // 反轉匹配邊以及未匹配邊的狀態
            }
        }
    }
    return false;
}
void solve() {  // 記得每次使用需清空 vis
    for (int i = 1; i <= n; i++)
        S[i] = -1;
    for (int i = 1; i <= p; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i))
            ans++;
    }
}
