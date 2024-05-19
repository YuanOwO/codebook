#define ld long double
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
    ld operator*(const Pt &a) {  // 計算幾何程式碼中內積通常用*表示
        return x * a.x + y * a.y;
    }
    ld operator^(const Pt &a) {  // 計算幾何程式碼中外積通常用^表示
        return x * a.y - y * a.x;
    }
    bool operator<(const Pt &a) const {  // 判斷兩點座標 先比 x 再比 y
        return x < a.x || (x == a.x && y < a.y);
    }
    friend ld cross(Pt a, Pt b, Pt o) {
        Pt p1 = a - o, p2 = b - o;
        return p1.x * p2.y - p1.y * p2.x;
    }

    // for long long
    bool collinearity(Pt &a, Pt &b, Pt &c) {
        return ((b - a) ^ (c - a)) == 0;
    }
    bool inLine(Pt &p, Pt &a, Pt &b) {
        return collinearity(a, b, p) && (a - p) * (b - p) < 0;
    }

    // for long double
    bool collinearity(Pt &a, Pt &b, Pt &c, ld EPS) {
        return ((b - a) ^ (c - a)) < EPS;
    }
    bool inLine(Pt &p, Pt &a, Pt &b, ld EPS) {
        return collinearity(a, b, p) && (a - p) * (b - p) < EPS;
    }
};
