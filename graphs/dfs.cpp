#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n + m))

typedef vector<vector<int>> Graph;

void dfs_traverse(Graph &graph, vector<bool> &used, int cur) {
    used[cur] = true;

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next)
        if (!used[*next])
            dfs_traverse(graph, used, *next);
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n, vector<int>());

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<bool> used(n, false);

    dfs_traverse(graph, used, 0);

    copy(used.begin(), used.end(), ostream_iterator<bool>(cout, " "));
}

