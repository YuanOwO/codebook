/**
 * @brief 計算幾何一些常用功能
 *
 * @param o1 圓1的圓心座標
 * @param r1 圓1的半徑
 * @param o2 圓2的圓心座標
 * @param r2 圓2的半徑
 *
 * @return 兩圓的交點
 *
 * 備註: 回傳 vector 如果為空 就是沒交點
 */

vector<Pt> interCircle(Pt o1, ld r1, Pt o2, ld r2) {
    if (norm(o1 - o2) > r1 + r2)
        return {};
    if (norm(o1 - o2) < max(r1, r2) - min(r1, r2))
        return {};
    ld d2 = (o1 - o2) * (o1 - o2);
    ld d = sqrt(d2);
    if (d > r1 + r2)
        return {};
    Pt u =
        (o1 + o2) * 0.5 + (o1 - o2) * ((r2 * r2 - r1 * r1) / (2 * d2));
    ld A = sqrt((r1 + r2 + d) * (r1 - r2 + d) * (r1 + r2 - d) *
                (-r1 + r2 + d));
    Pt v = Pt(o1.y - o2.y, -o1.x + o2.x) * A / (2 * d2);
    return {u + v, u - v};
}
