#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(m)

typedef vector<vector<bool>> Graph;

void dfs_euler_path(Graph &graph, vector<pair<int, int>> &euler_path, int cur) {
    int next = 0;
    while (next != graph[cur].size() && !graph[cur][next]) ++next;

    if (next == graph[cur].size()) return;

    graph[cur][next] = graph[next][cur] = false;

    euler_path.push_back(make_pair(cur, next));
    dfs_euler_path(graph, euler_path, next);
}

vector<pair<int, int>> find_euler_path(Graph &graph) {
    int v1 = -1,
        v2 = -1;
    bool all_even = true;

    vector<int> degree(graph.size());
    vector<pair<int, int>> euler_path;

    for (int i = 0; i < graph.size(); ++i)
        for (int j = 0; j < graph[i].size(); ++j)
            degree[i] += graph[i][j] ? 1 : 0;

    for (int i = 0; i < graph.size(); ++i) {
        if (degree[i] % 2 == 0) continue;

        all_even = false;

        if (v1 == -1)
            v1 = i;
        else if (v2 == -1)
            v2 = i;
        else {
            euler_path.push_back(make_pair(-1, -1));
            return euler_path;
        }
    }

    if (v1 == -1) {
        v1 = 0;
        while (!degree[v1]) v1++;

        v2 = graph[v1].size() - 1;
        while (!graph[v1][v2]) v2--;

        graph[v1][v2] = graph[v2][v1] = false;
    }

    dfs_euler_path(graph, euler_path, v1);

    if (all_even)
        euler_path.push_back(make_pair(v2, v1));

    return euler_path;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n, vector<bool>(n, false));

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;

        graph[from][to] = graph[to][from] = true;
    }

    vector<pair<int, int>> euler_path = find_euler_path(graph);
    for (auto it = euler_path.begin(); it < euler_path.end(); ++it)
        cout << it->first << " " << it->second << endl;
}

