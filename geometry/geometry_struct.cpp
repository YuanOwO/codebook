int dcmp(ld x) {  // 處理小數點精度的東東
    if (abs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
struct Pt {
    ld x, y;
    Pt(ld _x = 0, ld _y = 0) : x(_x), y(_y) {}
    Pt operator+(const Pt &a) {
        return Pt(x + a.x, y + a.y);
    }
    Pt operator-(const Pt &a) {
        return Pt(x - a.x, y - a.y);
    }
    Pt operator*(const ld &a) {
        return Pt(x * a, y * a);
    }
    Pt operator/(const ld &a) {
        return Pt(x / a, y / a);
    }
    ld operator*(const Pt &a) {  // 內積
        return x * a.x + y * a.y;
    }
    ld operator^(const Pt &a) {  // 行列式(叉乘)
        return x * a.y - y * a.x;
    }
    bool operator<(const Pt &a) const {
        return x < a.x || (x == a.x && y < a.y);
    }
    friend ld cross(Point a, Point b, Point o) {
        // 行列式(叉乘)，存入三個點
        Point p1 = a - o, p2 = b - o;
        return p1.x * p2.y - p1.y * p2.x;
    }
    // return dcmp(x-a.x) < 0 || (dcmp(x-a.x) == 0 && dcmp(y-a.y) < 0);
    // }
    bool operator==(const Pt &a) {
        return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0;
    }
};

ld norm2(const Pt &a) {  // 平方
    return a * a;
}
ld norm(const Pt &a) {
    return sqrt(norm2(a));
}
Pt perp(const Pt &a) {  // 與原本向量垂直的向量
    return Pt(-a.y, a.x);
}
Pt rotate(const Pt &a, ld ang) {  // 旋轉矩陣
    return Pt(a.x * cos(ang) - a.y * sin(ang),
              a.x * sin(ang) + a.y * cos(ang));
}

struct Line {
    Pt s, e, v;  // start, end, end-start
    ld ang;
    Line(Pt _s = Pt(0, 0), Pt _e = Pt(0, 0)) : s(_s), e(_e) {
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
