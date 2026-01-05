/*最多有2n-1個狀態、3n-4個轉移，
parent tree上父節點是子節點的後綴，且endpos集合=所有子節點的endpos，
節點代表的字串個數是len(v)-len(link(v))，
常用對len大到小去拓排(葉到根)代替dfs，建構SAM時用static*/
const int MXN = 200005;
struct SAM {
    struct State {
        int len, link, sz;
        int next[26];
    } st[MXN];
    int sz, last;
    SAM(){
        st[0].len = 0;
        st[0].link = -1;
        st[0].sz = 0;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }
    SAM(string &s): SAM(){
        for(char ch : s) add(ch-'A');
    }
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
        if(p != -1 && st[p].next[ch] != cur){
            int q = st[p].next[ch];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            }
            else {
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
    void calc_endpos(){ // counting sort + bfs
        static int cnt[MXN], idx[MXN];
        int max_len = 0;
        for(int i = 0; i < sz; i++){
            max_len = max(max_len, st[i].len);
            cnt[i] = 0;
        }
        for(int i = 0; i < sz; i++) cnt[st[i].len]++;
        for(int i = 1; i <= max_len; i++) cnt[i] += cnt[i-1];
        for(int i = 0; i < sz; i++) idx[--cnt[st[i].len]] = i;
        for(int i = sz-1; i > 0; i--){
            int u = idx[i], f = st[u].link;
            if(f != -1) st[f].sz += st[u].sz;
        }
    }
};