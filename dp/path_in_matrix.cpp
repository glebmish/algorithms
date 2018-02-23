#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(vector<vector<int>> &vec) {
    int n = vec.size();

    vector<vector<int>> dp(n, vector<int>(n));
    for (int j = 0; j < vec.size(); ++j) {
        dp[0][j] = vec[0][j];
    }

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + vec[i][0];

        for (int j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + vec[i][j];

            if (j + 1 < n) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + vec[i][j]);
            }
        }
    }

    int mx = 0;
    for (int j = 0; j < n; ++j) {
        mx = max(mx, dp[n - 1][j]);
    }
    return mx;
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        vector<vector<int>> vec(N, vector<int>(N));
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                cin >> vec[j][k];
            }
        }

        cout << solve(vec) << endl;
    }
    return 0;
}