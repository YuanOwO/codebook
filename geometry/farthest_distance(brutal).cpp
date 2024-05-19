#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN = 2e5 + 5;

struct Point {
    ll x, y;

    bool operator<(const Point &a) const {
        if (x == a.x)
            return y < a.y;
        return x < a.x;
    }

    friend ll sq_dis(Point a, Point b) {
        ll dis = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
        return dis;
    }
} p[MAXN];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;

    ll mn = LLONG_MAX;
    sort(p, p + n);

    set<Point> dp = {
        {p[0].y, p[0].x}
    };

    for (int i = 1, j = 0; i < n; i++) {
        ll d = ceil(sqrt(mn));
        while (j < i && p[j].x < p[i].x - d)
            dp.erase({p[j].y, p[j].x}), j++;
        auto l = dp.lower_bound({p[i].y - d, 0});
        auto r = dp.upper_bound({p[i].y + d, 0});

        for (auto it = l; it != r; it++)
            mn = min(mn, sq_dis({it->y, it->x}, p[i]));
        dp.insert({p[i].y, p[i].x});
    }
    cout << mn << '\n';

    return 0;
}
