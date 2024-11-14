int dcmp(ld x) {  // 處理小數點精度的東東
  if (abs(x) < EPS) return 0;
  else return x < 0 ? -1 : 1;
}
struct Pt {
  ld x, y;
  Pt(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
};
Pt operator+(const Pt &a, const Pt &b) {
  return Pt(a.x + b.x, a.y + b.y);
}
Pt operator-(const Pt &a, const Pt &b) {
  return Pt(a.x - b.x, a.y - b.y);
}
Pt operator*(const Pt &a, const ld &b) {
  return Pt(a.x * b, a.y * b);
}
Pt operator/(const Pt &a, const ld &b) {
  return Pt(a.x / b, a.y / b);
}
ld operator*(const Pt &a, const Pt &b) {  // 內積
  return a.x * b.x + a.y * b.y;
}
ld operator^(const Pt &a, const Pt &b) {  // 行列式 (叉乘)
  return a.x * b.y - a.y * b.x;
}
bool operator<(const Pt &a, const Pt &b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
  // return dcmp(a.x - b.x) < 0 ||
  // (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}

ld cross(Pt a, Pt b, Pt o) {  // 行列式(叉乘)，存入三個點
  Pt p1 = a - o, p2 = b - o;
  return p1.x * p2.y - p1.y * p2.x;
}
bool operator==(const Pt &a, const Pt &b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
// 平方
ld norm2(const Pt &a) { return a * a; }
ld norm(const Pt &a) { return sqrt(norm2(a)); }
// 與原本向量垂直的向量
Pt perp(const Pt &a) { return Pt(-a.y, a.x); }
// 旋轉矩陣
Pt rotate(const Pt &a, ld rad) {
  return Pt(a.x * cos(rad) - a.y * sin(rad),
            a.x * sin(rad) + a.y * cos(rad));
}

struct Line {
  Pt s, e, v;  // start, end, end-start
  ld ang;      // 斜率的樣子?
  Line(Pt _s = Pt(0, 0), Pt _e = Pt(0, 0))
      : s(_s), e(_e) {
    v = e - s;
    ang = atan2(v.y, v.x);
  }
  bool operator<(const Line &L) const {
    return ang < L.ang;
  }
};

struct Circle {
  Pt o;
  ld r;
  Circle(Pt _o = Pt(0, 0), ld _r = 0) : o(_o), r(_r) {}
};
