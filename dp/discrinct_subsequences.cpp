// number of ways to from s2 from s1

int Solution::numDistinct(string s1, string s2) {
    int n = s2.size() + 1;
    vector<int> prev(n, 0);
    vector<int> cur(n);

    prev[0] = 1;

    for (int i = 0; i < s1.size(); ++i) {
        cur[0] = 1;

        for (int j = 1; j < n; ++j) {
            cur[j] = prev[j];

            if (s1[i] == s2[j - 1]) {
                cur[j] += prev[j - 1];
            }
        }

        prev = cur;
        cur = vector<int>(n);
    }

    return prev.back();
}
