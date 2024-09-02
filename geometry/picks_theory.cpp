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