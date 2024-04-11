/**
 * 割圓術始載於三國魏·劉徽《九章算術注》
 */

#include <cmath>
#define ll long long
#define ld long double

const ll 半徑 = 1, 半徑平方 = 半徑 * 半徑;

ll 冪(ll 底數, ll 指數) {
    ll 答 = 1;
    while (指數) {
        if (指數 & 1)
            答 = 答 * 底數;
        底數 = 底數 * 底數;
        指數 >>= 1;
    }
    return 答;
}

ld 求小弦(ld 裏觚之面, ll 輪數) {
    if (輪數 < 1)
        return 裏觚之面;

    ld 半面 = 裏觚之面 / 2;
    ld 半面平方 = 半面 * 半面;
    ld 股 = sqrt(半徑平方 - 半面平方);
    ld 小句 = 半徑 - 股;
    ld 小弦 = sqrt(小句 * 小句 + 半面平方);

    return 求小弦(小弦, 輪數 - 1);
}

ld 割圓術求圓周率(ll 輪數) {
    輪數 -= 1;
    ll 觚數 = 冪(2, 輪數) * 6;
    ld 小弦 = 求小弦(半徑, 輪數);
    ld 觚周 = 小弦 * 觚數;
    ld 觚冪 = (觚周 / 2) * 半徑;
    ld 圓周率 = 觚冪 / 半徑平方;
    return 圓周率;
}
