#include <iostream>
#include <vector>
using namespace std;

unsigned long long solve(int n) {
    vector<unsigned long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i < dp.size(); ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (i - j >= 0) {
                dp[i] += dp[i - j];
            }
        }
    }

    return dp.back();
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        cout << solve(N) << endl;
    }
    return 0;
}