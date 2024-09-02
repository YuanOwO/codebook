int ans[MAXN << 1];
char s[MAXN << 1];
string ret;  // 迴文字串儲存結果
void find_palindrome(char *s, int len, int *z) {
    int idx = 0, mx = -1;
    for (int i = 0; i < len; i++) {  // 找迴文半徑最大值
        if (mx < ans[i]) {
            idx = i;
            mx = ans[i];
        }
    }
    for (int i = idx - mx + 1; i < idx; i++)
        if (s[i] != '@')
            ret.push_back(s[i]);
    for (int i = idx; i <= idx + mx - 1; i++)
        if (s[i] != '@')
            ret.push_back(s[i]);
    // cout << ret << '\n'; //// 直接輸出
}
void z_value_pal(char *s, int len, int *z) {  // 字串，長度，輸出的陣列
    len = (len << 1) + 1;
    for (int i = len - 1; i >= 0; i--)
        s[i] = i & 1 ? s[i >> 1] : '@';
    z[0] = 1;
    for (int i = 1, l = 0, r = 0; i < len; i++) {
        z[i] = i < r ? min(z[l + l - i], r - i) : 1;
        while (i - z[i] >= 0 && i + z[i] < len &&
               s[i - z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] > r)
            l = i, r = i + z[i];
    }
    find_palindrome(s, strlen(s), z);
}
