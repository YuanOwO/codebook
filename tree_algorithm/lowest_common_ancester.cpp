#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5, logN = 20;
vector<int> g[N];

int timing = 1;
int in[N], out[N];
int anc[N][logN];

// 建立倍增表
void build_table() {
    for (int i = 1; i <= log2(N); i++) {
        for (int now = 1; now <= N; now++) {
            anc[now][i] = anc[anc[now][i - 1]][i - 1];
        }
    }
}

// 建立時間戳記
void dfs_init(int u) {
    in[u] = timing++;       // 這時進入u
    for (int nxt : g[u]) {  // 跑過所有孩子
        dfs_init(nxt);
    }
    out[u] = timing++;  // 這時離開u
}

// 判斷是否是祖先
bool is_ancestor(int u, int v) {
    return (in[u] < in[v] && out[v] < out[u]);
}

// 跑一遍 DFS 得到誰是誰的父親
void dfs(int now, int fa) {  // 現在的點、父節點
    anc[now][0] = fa;        // now的0倍祖先是pre
    for (auto i : g[now]) {
        if (i == fa)
            continue;
        dfs(i, now);
    }
}

// 找最低共同祖先
int getlca(int x, int y) {
    if (is_ancestor(x, y))  // 如果 u 為 v 的祖先則 lca 為 u
        return x;
    if (is_ancestor(y, x))  // 如果 v 為 u 的祖先則 lca 為 u
        return y;

    // 判斷 2^logN, 2^(logN-1),...2^1, 2^0 倍祖先
    for (int i = logN; i >= 0; i--) {
        if (!is_ancestor(anc[x][i], y))  // 如果 2^i 倍祖先不是 v 的祖先
            x = anc[x][i];               // 則往上移動
    }
    return anc[x][0];  // 回傳此點的父節點即為答案
}

// 以下是樹上差分
int tag[N], f[N], ans[N], root;
void add(int x, int y) {
    int lca = getlca(x, y);
    tag[x]++;
    tag[y]++;
    tag[lca]--;
    if (lca != root)
        tag[f[lca]]--;
}

int dfs_add(int now, int fa) {
    int diff = tag[now];
    for (auto nxt : g[now]) {
        if (nxt == fa)
            continue;
        diff += dfs_add(nxt, now);
    }
    return ans[now] = diff;
}
