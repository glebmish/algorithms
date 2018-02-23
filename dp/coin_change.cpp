#include <iostream>
#include <vector>
using namespace std;

int change(int C, vector<int>& coins) {
    int n = C + 1;
    vector<int> prev(n, 0);
    vector<int> cur(n);

    for (int i = 0; i < coins.size(); ++i) {
        cur[0] = 1;

        for (int j = 1; j < n; ++j) {
            cur[j] = prev[j];

            if (j - coins[i] >= 0) {
                cur[j] += cur[j - coins[i]];
            }
        }

        prev = cur;
        cur = vector<int>(n);
    }

    return prev.back();
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N;
        cin >> N;

        vector<int> coins(N);
        for (int i = 0; i < N; ++i) {
            cin >> coins[i];
        }

        int C;
        cin >> C;

        cout << change(C, coins) << endl;
    }
    return 0;
}