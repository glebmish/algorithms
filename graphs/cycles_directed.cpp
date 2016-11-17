#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n + m)

typedef vector<vector<int>> Graph;

bool dfs(Graph &graph, vector<int> &used, int cur) {
    if (used[cur] == 1) return true;
    if (used[cur] == 2) return false;
    used[cur] = 1;

    for (auto next = graph[cur].begin(); next != graph[cur].end(); ++next)
        if (dfs(graph, used, *next))
            return true;

    used[cur] = 2;
    return false;
}

bool cycles_directed(Graph graph) {
    vector<int> used(graph.size(), 0);

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
    }

    cout << cycles_directed(graph);
}

