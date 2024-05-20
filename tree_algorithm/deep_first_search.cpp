#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e6 + 5;
vector<int> tree[MAXN];

void dfs(int u, int pre) {
    for (int v : tree[u]) {
        if (pre == v)
            continue;
        dfs(v, u);
    }
}
