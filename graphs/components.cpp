#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n + m)

typedef vector<vector<int>> Graph;

void dfs(Graph &graph, vector<bool> &used, vector<int> &component, int cur) {
    used[cur] = true;
    component.push_back(cur);

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next)
        if (!used[*next])
            dfs(graph, used, component, *next);
}

int graph_components(Graph &graph) {
    vector<bool> used(graph.size(), false);
    int counter = 0;

    for (int i = 0; i < graph.size(); ++i)
        if (!used[i]) {
            counter++;

            vector<int> component;
            dfs(graph, used, component, i);
            copy(component.begin(), component.end(), ostream_iterator<int>(cout, " "));
            cout << endl;
        }

    return counter;
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

    cout << graph_components(graph);
}

