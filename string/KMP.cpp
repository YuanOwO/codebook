int failure[MXN];
vector<int> KMP(string& t, string& p) {
    vector<int> ret;  // 要保證長度 t > p
    for (int i = 1, j = failure[0] = -1; i < p.size(); ++i) {
        while (j >= 0 && p[j + 1] != p[i])
            j = failure[j];
        if (p[j + 1] == p[i])
            j++;
        failure[i] = j;
    }
    for (int i = 0, j = -1; i < t.size(); ++i) {
        while (j >= 0 && p[j + 1] != t[i])
            j = failure[j];
        if (p[j + 1] == t[i])
            j++;
        if (j == p.size() - 1) {
            ret.push_back(i - p.size() + 1);
            j = failure[j];
        }
    }
    return ret;
}