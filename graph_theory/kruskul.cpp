#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    sort(graph, graph + m);  // 將邊照大小排序
    int ans = 0;

    for (int i = 0; i < m; i++) {                    //>:)
        if (find(graph[i].u) != find(graph[i].v)) {  // 如果兩點未聯通
            merge(graph[i].u, graph[i].v);           // 將兩點設成同一個集合
            ans += graph[i].w;                       // 權重加進答案
            if (sz[find(graph[i].u)] == n)
                break;  // 當並查集大小等價於樹內點的數量
        }
    }

    cout << ans << endl;
}