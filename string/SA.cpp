const int MXN = 100005;
struct SA {
  int n;
  vector<int> rk, oldrk, sa, h;
  string s;
  SA(string& t)
      : s(t),
        n(t.size()),
        rk(n << 1),
        oldrk(n << 1),
        sa(n),
        h(n) {
    for (int i = 0; i < n; i++)
      rk[i] = s[i] - 'a' + 1, sa[i] = i;
    for (int w = 1; w < n; w <<= 1) {
      sort(sa.begin(), sa.end(), [&](int x, int y) {
        return (rk[x] == rk[y]) ? (rk[x + w] < rk[y + w])
                                : (rk[x] < rk[y]);
      });
      oldrk = rk;
      rk[sa[0]] = 1;
      for (int i = 1, p = 1; i < n; i++) {
        if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
            oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
          rk[sa[i]] = p;
        else rk[sa[i]] = ++p;
      }
    }
    for (int i = 0, k = 0; i < n; i++) {
      if (rk[i] == 1) continue;
      if (k) k--;
      while (s[i + k] == s[sa[rk[i] - 2] + k]) k++;
      h[rk[i] - 1] = k;
    }
  }
  void find(string p) {  // binary search
    int l = 0, r = n, m = p.size();
    if (m > n) return;
    for (int i = 0; i < m; i++) {
      auto cmp = [&](int lhs, int rhs) {
        return s[lhs + i] < rhs;
      };
      auto nl =
          lower_bound(sa + l, sa + r, p[i], cmp) - sa;
      auto nr =
          lower_bound(sa + l, sa + r, p[i] + 1, cmp) - sa;
      l = nl, r = nr;
      if (l >= r) break;
    }
    cout << (r > l ? "YES" : "NO") << "\n";
  }
};
