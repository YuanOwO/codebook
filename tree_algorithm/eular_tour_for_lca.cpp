#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

vector<int> tour, edge[N];
int timing = 0;
int in[N], out[N];

void dfs(int u, int fa) {
    tour.push_back(u);  // 進入的時間點
    in[u] = tour.size() - 1;
    for (auto v : edge[u]) {
        if (v == fa)
            continue;
        dfs(v, u);
        tour.push_back(u);  // 走完其中一個孩子 再走回自己
    }
    out[u] = tour.size() - 1;
}

void build(vector<int>& tour) {  // 把tour丟進線段樹初始化
    seg.build(tour);  // 除了tour，還要建每個點的深度
}

int query(int x, int y) {
    if (is_ancster(x, y))
        return x;  // LCA(x,y)=x
    if (is_ancster(y, x))
        return y;  // LCA(x,y)=y;
    if (out[y] < in[x])
        swap(x, y);  // 如果「y的區間」在「x的區間」的左邊，就交換
    int index =
        seg.query(out[x], in[y]);  // 取得區間內哪個位置的深度是最低的
    return tour[index];
}
