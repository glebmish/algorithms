#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

typedef vector<vector<int>> Graph;

bool try_kuhn(int v, Graph &g, vector<bool> &used, vector<int> &match) {
    if (used[v])
        return false;

    used[v] = true;

    for (int i = 0; i < g[v].size(); ++i) {
        int to = g[v][i];

        if (match[to] == -1 || try_kuhn(match[to], g, used, match)) {
            match[to] = v;
            return true;
        }
    }

    return false;
}

int main() {
    int n, n_edges, k;
    cin >> n >> k;
    cin >> n_edges;

    Graph n_to_k(n, vector<int>());

    for (int i = 0; i < n_edges; ++i) {
        int n_from, k_to;
        cin >> n_from >> k_to;

        n_to_k[n_from].push_back(k_to);
    }

    vector<int> match(k, -1);
    vector<bool> used;

    for (int v = 0; v < n; ++v) {
        used.assign(n, false);
        try_kuhn(v, n_to_k, used, match);
    }

    for (int i = 0; i < k; ++i)
        if (match[i] != -1)
            cout << match[i] << " " << i << endl;
}