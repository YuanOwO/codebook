/**
 * @brief 凸包 Convex Hull
 *
 * 用法: 呼叫 convex_hull() 傳入 存入所有點的 vector
 * 結果: 獲得凸包逆時針的點
 *
 */

double cross(Pt o, Pt a, Pt b) {
    return (a - o) ^ (b - o);
}
vector<Pt> convex_hull(vector<Pt> pt) {
    sort(pt.begin(), pt.end());
    int top = 0;
    vector<Pt> stk(2 * pt.size());
    for (int i = 0; i < (int)pt.size(); i++) {
        while (top >= 2 &&
               cross(stk[top - 2], stk[top - 1], pt[i]) <= 0)
            top--;
        stk[top++] = pt[i];
    }
    for (int i = pt.size() - 2, t = top + 1; i >= 0; i--) {
        while (top >= t &&
               cross(stk[top - 2], stk[top - 1], pt[i]) <= 0)
            top--;
        stk[top++] = pt[i];
    }
    stk.resize(top - 1);
    return stk;
}
