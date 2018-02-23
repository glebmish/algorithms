#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <limits>
using namespace std;

int solve(vector<int> &vec) {
    int sum = 0;
    for (int i = 0; i < vec.size(); ++i) {
        sum += vec[i];
    }

    vector<vector<bool>> dp(vec.size() + 1, vector<bool>(sum + 1, false));

    for (int i = 0; i <= vec.size(); ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= vec.size(); ++i) {
        for (int j = 1; j <= sum; ++j) {
            dp[i][j] = dp[i - 1][j];

            if (vec[i - 1] <= j) {
                dp[i][j] = dp[i][j] | dp[i - 1][j - vec[i - 1]];
            }
        }
    }

    for (int j = sum / 2; j >=0; --j) {
        if (dp[vec.size()][j]) {
            return sum - j * 2;
        }
    }

    return numeric_limits<int>::max();
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        vector<int> vec(N);
        for (int j = 0; j < N; ++j) {
            cin >> vec[j];
        }

        cout << solve(vec) << endl;
    }
    return 0;
}