struct DSU {
  int n;
  vector<int> f, sz;
  DSU(int _n) : n(_n) {  // 初始化
    f.resize(n);
    sz.resize(n);
    for (int i = 0; i < n; i++) f[i] = i, sz[i] = 1;
  }
  int find(int x) {  // 返回 x 的根節點
    if (x == f[x]) return x;
    return f[x] = find(f[x]);
  }
  void merge(int x, int y) {  // 將 x 和 y 合併
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] < sz[y]) swap(x, y);  // 將小的併入大的
    sz[x] += sz[y];
    f[y] = x;
  }
};
