struct Query {
  int l, r, id;  // 左界、右界、編號
  Query(int _l, int _r, int _id)
      : l(_l), r(_r), id(_id) {}
  friend bool operator<(const Query &lhs,
                        const Query &rhs) {
    if (lhs.l / k == rhs.l / k)  // 如果在同一塊就比較 r
      return lhs.r < rhs.r;
    return lhs.l < rhs.l;  // 如果在不同快就比較 l
  }
};

vector<Query> q;  // 詢問

void add(int idx) {
  // ... 自己推喔
}

void sub(int idx) {
  // ... 自己推喔
}

void mos_algorithm() {
  k = sqrt(n);  // n 個東西分成 k 塊
  sort(q.begin(), q.end());
  for (int i = 0, l = 1, r = 0; i < m; i++) {
    while (l > q[i].l)
      add(--l);
    while (r < q[i].r)
      add(++r);
    while (l < q[i].l)
      sub(l++);
    while (r > q[i].r)
      sub(r--);
    ans[q[i].id] = cur;  // 每一題長不一樣
  }
}
