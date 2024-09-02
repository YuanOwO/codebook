vector<int> edge[MAXN], ans;
int deg[MAXN];      // in degree
void topo(int n) {  // 1-base
    queue<int> que;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            que.push(i);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ans.push_back(u);
        // 結果存 ans
        for (int v : edge[u]) {
            deg[v]--;
            if (!deg[v])
                que.push(v);
        }
    }
}
