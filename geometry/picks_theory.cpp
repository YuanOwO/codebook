#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 1e5 + 5;
struct Point {
    ll x, y;

    Point operator-(const Point &a) {
        return {x - a.x, y - a.y};
    }

    friend ll cross(Point a, Point b, Point o) {
        Point p1 = a - o, p2 = b - o;
        return p1.x * p2.y - p1.y * p2.x;
    }
} p[MAXN];

ll compute_area(int n) {  // A*2
    ll area = 0;
    for (int i = 1; i < n; i++)
        area += cross(p[i], p[(i + 1) % n], p[0]);
    area = abs(area);
    return area;
}

ll compute_pt_on_line(int n) {  // b
    ll pt = 0;
    for (int i = 0; i < n; i++)
        pt += __gcd(abs(p[i].x - p[(i + 1) % n].x),
                    abs(p[i].y - p[(i + 1) % n].y));
    return pt;
}

ll compute_inner_pt(int n) {  // i
    return (compute_area(n) - compute_pt_on_line(n)) / 2 + 1;
}
