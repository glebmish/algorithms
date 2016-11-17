#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n + m)

typedef vector<vector<int>> Graph;

bool dfs(Graph &graph, vector<bool> &used, int cur, int parent = -1) {
    if (used[cur]) return true;
    used[cur] = true;

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next) {
        if (*next != parent && dfs(graph, used, *next, cur))
            return true;
    }

    return false;
}

bool is_cycles(Graph &graph) {
    vector<bool> used(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i)
        if (!used[i] && dfs(graph, used, i))
            return true;

    return false;
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

    cout << is_cycles(graph) << endl;
}

