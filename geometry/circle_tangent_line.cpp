/**
 * @brief 兩圓公切線
 *
 * @param c1 圓1的結構
 * @param c2 圓2的結構
 * @param sign1 1: 外公切線; -1: 內公切線
 *
 * @return 兩圓的公切線
 *
 * 備註:
 * 回傳的 vector<Line> 中
 * 第一個是圓1的切點
 * 第二個是圓2的切點
 */

vector<Line> go(const Circle& c1, const Circle& c2, int sign1) {
    // sign1 = 1 for outer tang, -1 for inter tang
    vector<Line> ret;
    double d_sq = norm2(c1.o - c2.o);
    if (d_sq < eps)
        return ret;
    double d = sqrt(d_sq);
    Pt v = (c2.o - c1.o) / d;
    double c = (c1.r - sign1 * c2.r) / d;
    if (c * c > 1)
        return ret;
    double h = sqrt(max(0.0, 1.0 - c * c));
    for (int sign2 = 1; sign2 >= -1; sign2 -= 2) {
        Pt n = {v.x * c - sign2 * h * v.y, v.y * c + sign2 * h * v.x};
        Pt p1 = c1.o + n * c1.r;
        Pt p2 = c2.o + n * (c2.r * sign1);
        if (fabs(p1.x - p2.x) < eps and fabs(p1.y - p2.y) < eps)
            p2 = p1 + perp(c2.o - c1.o);
        ret.push_back({p1, p2});
    }
    return ret;
}
