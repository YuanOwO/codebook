namespace blossom {
#define d(x) (lab[x.u] + lab[x.v] - 2 * e[x.u][x.v].w)
#define all(x) x.begin(), x.end()
const ll N = 403 * 2;
const ll inf = 1e18;
struct Q {
  ll u, v, w;
} e[N][N];
vector<ll> p[N];
ll n, m = 0, id, h, t, lk[N], sl[N], st[N], f[N], b[N][N],
      s[N], ed[N], q[N], lab[N];
void upd(ll u, ll v) {
  if (!sl[v] || d(e[u][v]) < d(e[sl[v]][v])) sl[v] = u;
}
void ss(ll v) {
  sl[v] = 0;
  for (ll u = 1; u <= n; ++u)
    if (e[u][v].w > 0 && st[u] != v && !s[st[u]])
      upd(u, v);
}
void ins(ll u) {
  if (u <= n) q[++t] = u;
  else
    for (ll v : p[u]) ins(v);
}
void ch(ll u, ll w) {
  st[u] = w;
  if (u > n)
    for (ll v : p[u]) ch(v, w);
}
ll gr(ll u, ll v) {
  if ((v = find(all(p[u]), v) - p[u].begin()) & 1) {
    reverse(1 + all(p[u]));
    return (ll)p[u].size() - v;
  }
  return v;
}
void stm(ll u, ll v) {
  lk[u] = e[u][v].v;
  if (u <= n) return;
  Q w = e[u][v];
  ll x = b[u][w.u], y = gr(u, x);
  for (ll i = 0; i < y; ++i) stm(p[u][i], p[u][i ^ 1]);
  stm(x, v);
  rotate(p[u].begin(), y + all(p[u]));
}
void aug(ll u, ll v) {
  ll w = st[lk[u]];
  stm(u, v);
  if (!w) return;
  stm(w, st[f[w]]);
  aug(st[f[w]], w);
}
ll lca(ll u, ll v) {
  for (id++; u | v; swap(u, v)) {
    if (!u) continue;
    if (ed[u] == id) return u;
    ed[u] = id;
    if (u = st[lk[u]]) u = st[f[u]];  // =, not ==
  }
  return 0;
}
void add(ll u, ll a, ll v) {
  ll x = n + 1;
  while (x <= m && st[x]) ++x;
  if (x > m) ++m;
  lab[x] = s[x] = st[x] = 0;
  lk[x] = lk[a];
  p[x].clear();
  p[x].push_back(a);
#define op(q)                                       \
  for (ll i = q, j = 0; i != a; i = st[f[j]])       \
  p[x].push_back(i), p[x].push_back(j = st[lk[i]]), \
      ins(j)  // also not ==
  op(u);
  reverse(1 + all(p[x]));
  op(v);
  ch(x, x);
  for (ll i = 1; i <= m; ++i) e[x][i].w = e[i][x].w = 0;
  fill(b[x], b[x] + n + 1, 0);
  for (ll u : p[x]) {
    for (ll v = 1; v <= m; ++v)
      if (!e[x][v].w || d(e[u][v]) < d(e[x][v]))
        e[x][v] = e[u][v], e[v][x] = e[v][u];
    for (ll v = 1; v <= n; ++v)
      if (b[u][v]) b[x][v] = u;
  }
  ss(x);
}
void ex(ll u) {
  for (ll x : p[u]) ch(x, x);
  ll a = b[u][e[u][f[u]].u], r = gr(u, a);
  for (ll i = 0; i < r; i += 2) {
    ll x = p[u][i], y = p[u][i + 1];
    f[x] = e[y][x].u;
    s[x] = 1;
    s[y] = 0;
    sl[x] = 0;
    ss(y);
    ins(y);
  }
  s[a] = 1;
  f[a] = f[u];
  for (ll i = r + 1; i < p[u].size(); ++i)
    s[p[u][i]] = -1, ss(p[u][i]);
  st[u] = 0;
}
bool on(const Q &e) {
  ll u = st[e.u], v = st[e.v], a;
  if (s[v] == -1) {
    f[v] = e.u, s[v] = 1, a = st[lk[v]],
    sl[v] = sl[a] = s[a] = 0, ins(a);
  } else if (!s[v]) {
    a = lca(u, v);
    if (!a) return aug(u, v), aug(v, u), 1;
    else add(u, a, v);
  }
  return 0;
}
bool bfs() {
  fill(s, s + m + 1, -1);
  fill(sl, sl + m + 1, 0);  // s is filled with -1
  h = 1, t = 0;
  for (ll i = 1; i <= m; ++i)
    if (st[i] == i && !lk[i]) f[i] = s[i] = 0, ins(i);
  if (h > t) return 0;
  while (1) {
    while (h <= t) {
      ll u = q[h++];
      if (s[st[u]] != 1) {
        for (ll v = 1; v <= n; ++v)
          if (e[u][v].w > 0 && st[u] != st[v]) {
            if (d(e[u][v])) upd(u, st[v]);
            else if (on(e[u][v])) return 1;
          }
      }
    }
    ll x = inf;
    for (ll i = n + 1; i <= m; ++i)
      if (st[i] == i && s[i] == 1) x = min(x, lab[i] / 2);
    for (ll i = 1; i <= m; ++i)
      if (st[i] == i && sl[i] && s[i] != 1)
        x = min(x, d(e[sl[i]][i]) >> s[i] + 1);
    for (ll i = 1; i <= n; ++i)
      if (~s[st[i]])
        if ((lab[i] += (s[st[i]] * 2 - 1) * x) <= 0)
          return 0;
    for (ll i = n + 1; i <= m; ++i)
      if (st[i] == i && ~s[st[i]])
        lab[i] += (2 - 4 * s[st[i]]) * x;
    h = 1, t = 0;
    for (ll i = 1; i <= m; ++i)
      if (st[i] == i && sl[i] && st[sl[i]] != i &&
          !d(e[sl[i]][i]) && on(e[sl[i]][i]))
        return 1;
    for (ll i = n + 1; i <= m; ++i)
      if (st[i] == i && s[i] == 1 && !lab[i]) ex(i);
  }
}

pair<ll, vector<array<ll, 2>>> solve(
    ll N, vector<array<ll, 3>> edges) {
  for (auto &edge : edges) ++edge[0], ++edge[1];
  fill(ed, ed + m + 1, 0);
  fill(lk, lk + m + 1, 0);
  n = m = N;
  id = 0;
  iota(st + 1, st + n + 1, 1);
  ll wm = 0, weight = 0;
  for (ll i = 1; i <= n; ++i)
    for (ll j = 1; j <= n; ++j) e[i][j] = {i, j, 0};
  for (auto edge : edges) {
    int u = edge[0], v = edge[1];
    ll w = edge[2];
    wm = max(wm,
             e[v][u].w = e[u][v].w = max(e[u][v].w, w));
  }
  for (ll i = 1; i <= n; ++i) p[i].clear();
  for (ll i = 1; i <= n; ++i)
    for (ll j = 1; j <= n; ++j) b[i][j] = i == j ? i : 0;
  fill_n(lab + 1, n, wm);
  while (bfs()) {}
  vector<array<ll, 2>> matching;
  for (ll i = 1; i <= n; ++i)
    if (i < lk[i])
      weight += e[i][lk[i]].w,
          matching.push_back({i - 1, lk[i] - 1});
  return {weight, matching};
}
}  // namespace blossom
