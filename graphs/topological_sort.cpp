#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

// O(n + m)

typedef vector<vector<int>> Graph;

void dfs(Graph &graph, vector<bool> &used, vector<int> &order, int cur) {
    used[cur] = true;

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next)
        if (!used[*next])
            dfs(graph, used, order, *next);

    order.push_back(cur);
}

vector<int> topological_sort(Graph &graph) {
    vector<bool> used(graph.size(), false);
    vector<int> order;

    for (int i = 0; i < graph.size(); ++i)
        if (!used[i])
            dfs(graph, used, order, i);

    reverse(order.begin(), order.end());
    return order;
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

    vector<int> sorted = topological_sort(graph);

    copy(sorted.begin(), sorted.end(), ostream_iterator<int>(cout, " "));
}

