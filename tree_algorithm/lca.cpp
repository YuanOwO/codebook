bool is_ancestor(int u, int v) {  // 判斷 u 是否 v 是祖先
  return (in[u] < in[v] && out[v] < out[u]);
}
int getLCA(int x, int y) {  // 找最近共同祖先
  if (is_ancestor(x, y))    // 如果 x 為 y 的祖先
    return x;               // 則 LCA 為 y
  if (is_ancestor(y, x))    // 如果 y 為 x 的祖先
    return y;               // LCA 為 y
  for (int i = lgN; i >= 0; i--)  // 逼近 LCA
    if (!is_ancestor(anc[x][i], y) && anc[x][i])
      x = anc[x][i];
  return anc[x][0];  // 回傳此點的父節點即為答案
}
