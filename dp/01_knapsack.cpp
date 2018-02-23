#include <iostream>
#include <vector>
using namespace std;

int knaps(int W, vector<int>& v, vector<int>& w) {
    int n = W + 1;
    vector<int> prev(n, 0);
    vector<int> cur(n);

    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            cur[j] = prev[j];
            if (w[i] <= j) {
                cur[j] = max(cur[j], prev[j - w[i]] + v[i]);
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
        int N, W;
        cin >> N;
        cin >> W;

        vector<int> v(N), w(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        for (int i = 0; i < N; ++i) {
            cin >> w[i];
        }

        cout << knaps(W, v, w) << endl;
    }
    return 0;
}