#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solve(string &s1, string &s2) {
    int n = s2.size() + 1;
    vector<int> prev(n);
    vector<int> cur(n);

    for (int i = 0; i < n; ++i) {
        prev[i] = i;
    }

    for (int i = 0; i < s1.size(); ++i) {
        cur[0] = i + 1;

        for (int j = 1; j < n; ++j) {
            if (s1[i] == s2[j - 1]) {
                cur[j] = prev[j - 1];
            } else {
                cur[j] = min(prev[j - 1], min(cur[j - 1], prev[j])) + 1;
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
        int P, Q;
        cin >> P >> Q;

        string s1, s2;
        cin >> s1 >> s2;

        cout << solve(s1, s2) << endl;
    }
    return 0;
}