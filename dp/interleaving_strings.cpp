int Solution::isInterleave(string A, string B, string C) {
    if (C.size() != A.size() + B.size()) {
        return 0;
    }

    vector<vector<bool>> dp(A.size() + 1, vector<bool>(B.size() + 1, false));
    dp[0][0] = true;

    for (int i = 1; i < A.size() + 1; ++i) {
        if (C[i - 1] == A[i - 1]) {
            dp[i][0] = dp[i][0] || dp[i - 1][0];
        }
    }

    for (int j = 1; j < B.size() + 1; ++j) {
        if (C[j - 1] == B[j - 1]) {
            dp[0][j] = dp[0][j] || dp[0][j - 1];
        }
    }

    for (int i = 1; i < A.size() + 1; ++i) {
        for (int j = 1; j < B.size() + 1; ++j) {
            if (C[i + j - 1] == A[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];
            }
            if (C[i + j - 1] == B[j - 1]) {
                dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
    }

    return (dp.back().back()) ? 1 : 0;
}
