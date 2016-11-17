#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n + m)

typedef vector<vector<int>> Graph;

void dfs_traverse(Graph &graph, vector<bool> &used, vector<int> &order, int cur) {
    used[cur] = true;

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next)
        if (!used[*next])
            dfs_traverse(graph, used, order, *next);

    order.push_back(cur);
}

void dfs_component(Graph &graph, vector<bool> &used, vector<int> &component, int cur) {
    used[cur] = true;
    component.push_back(cur);

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next)
        if (!used[*next])
            dfs_component(graph, used, component, *next);
}

int graph_strong_components(Graph &graph, Graph &tr_graph) {
    int counter = 0;

    vector<bool> used(graph.size(), false);
    vector<int> order;

    for (int i = 0; i < graph.size(); ++i)
        if (!used[i])
            dfs_traverse(graph, used, order, i);

    used.assign(tr_graph.size(), false);

    for (int i = order.size() - 1; i >= 0; --i) {
        if (!used[order[i]]) {
            counter++;

            vector<int> component;
            dfs_component(tr_graph, used, component, order[i]);
            copy(component.begin(), component.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }
    }

    return counter;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n, vector<int>()),
          tr_graph(n, vector<int>());

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        tr_graph[to].push_back(from);
    }

    cout << graph_strong_components(graph, tr_graph);
}

