#define ll long long
const int MAXN = 1e5 + 5;

/**
 * @brief 皮克定理
 * A = i + b/2 − 1
 * 2A = 2i + b - 2 --- 同乘 2
 * i = A - b/2 + 1
 * A: 面積; b: 圖形內部的點數量; i: 圖形線上的點數量
 *
 * 用法: 先推公式 然後需要哪個就丟哪個函式
 *
 */

vector<Pt> p;

ll compute_area(int n) {  // A * 2
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
    return pt;  // 這是網路上找的
}

ll compute_inner_pt(int n) {  // i
    return (compute_area(n) - compute_pt_on_line(n)) / 2 + 1;
}
