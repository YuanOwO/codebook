const int MXN = 200005;
struct SAM {
    struct State {
        int len, link, sz;
        int next[26];
    } st[MXN << 1];
    int sz, last;
    int cnt[MXN << 1], idx[MXN << 1];
    SAM() { init();}
    void init() {
        st[0].len = 0;
        st[0].link = -1;
        st[0].sz = 0;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }
    void push(const string& s) { for (char c : s) add(c - 'a');}
    void add(int ch) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        st[cur].sz = 1;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        int p = last;
        while (p != -1 && st[p].next[ch] == -1) {
            st[p].next[ch] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[ch];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                st[clone].link = st[q].link;
                st[clone].sz = 0;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                
                while (p != -1 && st[p].next[ch] == q) {
                    st[p].next[ch] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }
    void topo() { // counting sort + bottom-up sz update
        int max_len = 0;
        for (int i = 0; i < sz; i++) {
            max_len = max(max_len, st[i].len);
            cnt[i] = 0;
        }
        for (int i = 0; i < sz; i++) cnt[st[i].len]++;
        for (int i = 1; i <= max_len; i++) cnt[i] += cnt[i - 1];
        for (int i = 0; i < sz; i++) idx[--cnt[st[i].len]] = i;
        for (int i = sz - 1; i > 0; i--) {
            int u = idx[i], f = st[u].link;
            if (f != -1){
                // root[f] = SegTree::merge(root[f], root[u], 1, n);
                st[f].sz += st[u].sz;
            }
        }
    }
    void trans(const string& t) {
        int cur = 0, step = 0;
        for (int i = 0; i < t.size(); i++) {
            int ch = t[i] - 'a';
            while (cur != -1 && st[cur].next[ch] == -1) {
                cur = st[cur].link;
                if (cur != -1) step = st[cur].len;
            }
            if (cur == -1) {
                cur = 0;
                step = 0;
            } else {
                cur = st[cur].next[ch];
                step++;
            }
        }
    }
} sam;
// 維護 endpos 集合
namespace SegTree{
    int ls[MXN * 50], rs[MXN * 50];
    int sum[MXN * 50];
    int tot = 0;
    void update(int &u, int l, int r, int pos){
        if(!u) u = ++tot;
        sum[u]++;
        if(l == r) return;
        int mid = l + ((r - l) >> 1);
        if(pos <= mid) update(ls[u], l, mid, pos);
        else update(rs[u], mid+1, r, pos);
    }
    int merge(int u, int v, int l, int r){
        if(!u || !v) return (u ? u : v);
        int node = ++tot; // node = u if no saving is required
        int mid = l + ((r - l) >> 1);
        ls[node] = merge(ls[u], ls[v], l, mid);
        rs[node] = merge(rs[u], rs[v], mid+1, r);
        sum[node] = sum[ls[node]] + sum[rs[node]];
        return node;
    }
    int query(int u, int l, int r, int ql, int qr){
        if(!u || ql > r || qr < l) return 0;
        if(ql <= l && r <= qr) return sum[u];
        int mid = l + ((r - l) >> 1);
        int res = 0;
        if(ql <= mid) res += query(ls[u], l, mid, ql, qr);
        if(qr > mid) res += query(rs[u], mid+1, r, ql, qr);
        return res;
    }
}