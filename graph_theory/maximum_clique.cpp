#define N 111

/**
 * @brief Finding Maximum Clique
 *
 * 團 Clique: 任選兩節點都有邊相連的圖
 * 最大團 Maximum Clique: 一張圖的子圖中最大的團
 * 獨立集 Independent Set: 一個圖中一些兩兩不相鄰的頂點所形成的集合
 * 最大獨立集 Maximum Independent Set: 最大團的補集 (補圖)
 *
 * 用法:
 * 1. init(n) 初始化圖 其中 n 為節點點數
 * 2. addEdge(u, v) 加入終點為 u, v 的無向邊
 * 3. solve() 跑 MaxClique
 * 結果:
 * - solve() 回傳回傳值為最大團的點數量
 * - cans(bitset): cans[i] 不是 0 的節點 i 都在最大獨立集裡
 *
 * 備註:
 * - 這模板是 0-base
 *
 * 複雜度: O((1.1888) ^ n)
 * 題目的 n 通常最大可以到 80 ~ 100 左右
 */

struct MaxClique {  // 0-base
    typedef bitset<N> Int;
    Int linkto[N], v[N];
    int n;
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            linkto[i].reset();
            v[i].reset();
        }
    }
    void addEdge(int a, int b) {
        v[a][b] = v[b][a] = 1;
    }
    int popcount(const Int& val) {
        return val.count();
    }
    int lowbit(const Int& val) {
        return val._Find_first();
    }
    int ans, stk[N];
    int id[N], di[N], deg[N];
    Int cans;
    void maxclique(int elem_num, Int candi) {
        if (elem_num > ans) {
            ans = elem_num;
            cans.reset();
            for (int i = 0; i < elem_num; i++)
                cans[id[stk[i]]] = 1;
        }
        int potential = elem_num + popcount(candi);
        if (potential <= ans)
            return;
        int pivot = lowbit(candi);
        Int smaller_candi = candi & (~linkto[pivot]);
        while (smaller_candi.count() && potential > ans) {
            int next = lowbit(smaller_candi);
            candi[next] = !candi[next];
            smaller_candi[next] = !smaller_candi[next];
            potential--;
            if (next == pivot ||
                (smaller_candi & linkto[next]).count()) {
                stk[elem_num] = next;
                maxclique(elem_num + 1, candi & linkto[next]);
            }
        }
    }
    int solve() {
        for (int i = 0; i < n; i++) {
            id[i] = i;
            deg[i] = v[i].count();
        }
        sort(id, id + n,
             [&](int id1, int id2) { return deg[id1] > deg[id2]; });
        for (int i = 0; i < n; i++)
            di[id[i]] = i;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (v[i][j])
                    linkto[di[i]][di[j]] = 1;
        Int cand;
        cand.reset();
        for (int i = 0; i < n; i++)
            cand[i] = 1;
        ans = 1;
        cans.reset();
        cans[0] = 1;
        maxclique(0, cand);
        return ans;
    }
} solver;
