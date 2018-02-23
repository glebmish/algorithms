#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int lcs(string &s1, string &s2) {
    if (s1.size() == 0 || s2.size() == 0) {
        return 0;
    }

    vector<int> prev(s2.size() + 1, 0);
    vector<int> cur(s2.size() + 1);

    for (int i = 1; i <= s1.size(); ++i) {
        cur[0] = 0;

        for (int j = 1; j <= s2.size(); ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                cur[j] = prev[j - 1] + 1;
            } else {
                cur[j] = max(prev[j], cur[j - 1]);
            }
        }

        prev = cur;
        cur = vector<int>(s2.size() + 1);
    }

    return prev.back();
}

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; ++i) {
        int N, M;
        cin >> N >> M;

        string str1, str2;
        cin >> str1 >> str2;

        cout << lcs(str1, str2) << endl;
    }
    return 0;
}