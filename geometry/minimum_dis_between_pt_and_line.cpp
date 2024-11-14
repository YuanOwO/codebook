#define EPS 1e-8
Pt P0, P1, A;
double check(double t) {  // 回傳點 A, B 的距離
  double B = P0 * t + P1 * (1.0 - t);
  return dis(A, B);
}
double PointAndSegmentDistance() {
  double l = 0.0, r = 1.0;
  while (r - l > EPS) {
    double ml = (l + l + r) / 3.0, mr = (l + r + r) / 3.0;
    if (check(ml) < check(mr)) r = mr;
    else l = ml;
  }
  return check(l);
}
