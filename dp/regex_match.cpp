int Solution::isMatch(const string str, const string pat) {
    int n = pat.size() + 1;
    vector<bool> prev(n, false);
    vector<bool> cur(n, false);
    prev[0] = true;

    for (int i = 1; i < n; ++i) {
        if (pat[i - 1] == '*') {
            prev[i] = prev[i - 1];
        }
    }

    for (int i = 0; i < str.size(); ++i) {
        for (int j = 1; j < n; ++j) {
            if (pat[j - 1] == '?' || str[i] == pat[j - 1]) {
                cur[j] = prev[j - 1];
            } else if (pat[j - 1] == '*') {
                cur[j] = prev[j - 1] || prev[j] || cur[j - 1];
            }
        }

        prev = cur;
        cur = vector<bool>(n, false);
    }

    return prev.back() ? 1 : 0;
}
