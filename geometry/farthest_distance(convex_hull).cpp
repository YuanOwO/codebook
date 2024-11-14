struct Pt {
  int x, y;
  Pt() {}
  Pt(int _x, int _y) { x = _x, y = _y; }
  Pt operator-(const Pt& a) {
    return Pt(x - a.x, y - a.y);
  }
  bool operator<(const Pt& a) const {
    return x < a.x || (x == a.x && y < a.y);
  }
  friend int cross(Pt& o, Pt& a, Pt& b) {
    Pt lhs = o - a, rhs = o - b;
    return lhs.x * rhs.y - lhs.y * rhs.x;
  }
  friend double distance(Pt a, Pt b) {
    return (a.x - b.x) * (a.x - b.x) +
           (a.y - b.y) * (a.y - b.y);
  }
};
vector<Pt> convex_hull(vector<Pt> hull) {
  sort(hull.begin(), hull.end());
  int top = 0;
  vector<Pt> stk;
  for (int i = 0; i < hull.size(); i++) {
    while (top >= 2 && cross(stk[top - 2], stk[top - 1],
                             hull[i]) <= 0)
      stk.pop_back(), top--;
    stk.push_back(hull[i]);
    top++;
  }
  for (int i = hull.size() - 2, t = top + 1; i >= 0;
       i--) {
    while (top >= t && cross(stk[top - 2], stk[top - 1],
                             hull[i]) <= 0)
      stk.pop_back(), top--;
    stk.push_back(hull[i]);
    top++;
  }
  stk.pop_back();
  return stk;
}
double FarthestPair(vector<Pt> arr) {
  double ret = 0;
  int sz = sz;
  for (int i = 0, j = i + 1; i < sz; i++) {
    while (distance(arr[i], arr[j]) <=
           distance(arr[i], arr[(j + 1) % sz])) {
      j = (j + 1) % sz;
    }
    ret = max(ret, distance(arr[i], arr[j]));
  }
  return ret;
}
