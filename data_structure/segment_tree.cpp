#define cl (i << 1)
#define cr (i << 1 | 1)
#define NO_TAG 0
#define INF 1e9

/**
 * @brief 線段樹 Segment Tree
 * 處理區間問題
 *
 * 用法:
 * 1. 初始化: 宣告 SegmentTree 結構時傳入 vec
 * 2. 詢問區間問題: query(l, r)
 * 3. 加值區間: update(l, r, v)
 * 備註:
 * 1. 必須使用 1-base 的陣列
 * 2. 如果要做單點 x 加值 可以寫 update(x, x, v)
 * 3. 如果是要修改值變成 v 可以先剪掉原本的值再加回 v
 * 4. 沒事不要亂改 n 會錯
 * 5. NO_TAG 的地方 需要懶人標記: 1, 不需要懶人標記: 0
 * 6. 以下寫 KK 的地方我也不知道是 [0, n-1] 還是 [1, n]
 */
struct SegmentTree {  // 1-base

    int n;
    vector<int> seg, tag;

    SegmentTree(int _n) {  // 空的 SegmentTree
        n = _n;
        seg.resize(n * 4);
        tag.resize(n * 4);
    }

    SegmentTree(vector<int>& arr) {  // 處理好的 SegmentTree
        n = arr.size();
        seg.resize(n * 4);
        tag.resize(n * 4);
        build(1, 0, n - 1, arr);  // kk
    }

    void push(int i, int l, int r) {
        if (tag[i] != NO_TAG) {
            seg[i] += tag[i];  // update by tag
            if (l != r) {
                tag[cl] += tag[i];  // push
                tag[cr] += tag[i];  // push
            }
            tag[i] = 0;
        }
    }

    void pull(int i, int l, int r) {
        int mid = (l + r) >> 1;
        push(cl, l, mid);
        push(cr, mid + 1, r);
        seg[i] = max(seg[cl], seg[cr]);  // pull
    }

    void build(int i, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[i] = arr[l];  // set value
            return;
        }
        int mid = (l + r) >> 1;
        build(cl, l, mid, arr);
        build(cr, mid + 1, r, arr);
        pull(i, l, r);
    }

    void update(int i, int l, int r, int ql, int qr, int v) {
        push(i, l, r);
        if (ql <= l && r <= qr) {
            tag[i] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if (ql <= mid)
            update(cl, l, mid, ql, qr, v);
        if (qr > mid)
            update(cr, mid + 1, r, ql, qr, v);
        pull(i, l, r);
    }

    int query(int i, int l, int r, int ql, int qr) {
        push(i, l, r);
        if (ql <= l && r <= qr) {
            return seg[i];
        }
        int mid = (l + r) >> 1, ans = -INF;
        if (ql <= mid)
            ans = max(ans, query(cl, l, mid, ql, qr));
        if (qr > mid)
            ans = max(ans, query(cr, mid + 1, r, ql, qr));
        return ans;
    }

    /**
     * @brief 區間 [ql, qr] 加值 v
     */
    void update(int ql, int qr, int v) {
        update(1, 0, n - 1, ql, qr, v);  // kk
    }

    /**
     * @brief 查詢區間 [ql, qr]
     */
    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);  // kk
    }
};
