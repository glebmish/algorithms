#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(vector<int> &vec) {
    vector<int> dp;
    int gmx = 1;

    dp.push_back(1);

    for (int i = 1; i < vec.size(); ++i) {
        int mx = 1;

        for (int j = i - 1; j >= 0; --j) {
            if (vec[i] > vec[j]) {
                mx = max(mx, dp[j] + 1);
                gmx = max(gmx, mx);
            }
        }

        dp.push_back(mx);
    }

    return gmx;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        if (N == 0) {
            cout << 0 << endl;
            continue;
        }

        vector<int> vec(N);

        for (int j = 0; j < N; ++j) {
            cin >> vec[j];
        }

        cout << solve(vec) << endl;
    }
    return 0;
}