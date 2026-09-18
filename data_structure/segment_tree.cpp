#define cl (i << 1)
#define cr (i << 1 | 1)
struct SegmentTree {  // 1-based
  int n;
  vector<int> seg, tag;

  SegmentTree(int _n) : n(_n) {
    seg.assign(4 * n + 5, 0);
    tag.assign(4 * n + 5, 0);
  }
  void apply(int i, int v) {
    seg[i] += v;
    tag[i] += v;
  }
  void push(int i) {
    if (tag[i] != 0) {
      apply(cl, tag[i]);
      apply(cr, tag[i]);
      tag[i] = 0;
    }
  }
  void pull(int i) {
    seg[i] = max(seg[cl], seg[cr]);
  }
  void build(int i, int l, int r, const vector<int>& arr) {
    if (l == r) {
      seg[i] = arr[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(cl, l, mid, arr);
    build(cr, mid + 1, r, arr);
    pull(i);
  }
  void update(int i, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
      apply(i, v);
      return;
    }
    push(i);
    int mid = (l + r) >> 1;
    if (ql <= mid) update(cl, l, mid, ql, qr, v);
    if (qr > mid) update(cr, mid + 1, r, ql, qr, v);
    pull(i);
  }
  int query(int i, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return seg[i];
    push(i);
    int mid = (l + r) >> 1, ans = -1e9;
    if (ql <= mid) ans = max(ans, query(cl, l, mid, ql, qr));
    if (qr > mid) ans = max(ans, query(cr, mid + 1, r, ql, qr));
    return ans;
  }
  void update(int ql, int qr, int v) { update(1, 1, n, ql, qr, v); }
  int query(int ql, int qr) { return query(1, 1, n, ql, qr); }
};