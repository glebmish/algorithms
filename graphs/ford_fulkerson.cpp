#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <queue>
using namespace std;

// O(m * flow)

#define INF 10000

typedef vector<vector<int>> Graph;

bool bfs(Graph &graph, int from, int to, vector<int> &parent) {
    vector<bool> used(graph.size(), false);

    queue<int> q;
    q.push(from);
    used[from] = true;
    parent[from] = -1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next = 0; next < graph[cur].size(); ++next)
            if (!used[next] && graph[cur][next] > 0) {
                q.push(next);
                parent[next] = cur;
                used[next] = true;
            }
    }

    return used[to] == true;
}

int ford_fulkerson(Graph &graph, int from, int to) {
    vector<int> parent(graph.size());

    int max_flow = 0;

    while (bfs(graph, from, to, parent)) {
        int path_flow = INF;

        for (int i = to; i != from; i = parent[i])
            path_flow = min(path_flow, graph[parent[i]][i]);

        for (int i = to; i != from; i = parent[i]) {
            graph[parent[i]][i] -= path_flow;
            graph[i][parent[i]] += path_flow;
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from][to] = weight;
    }

    int from, to;
    cin >> from >> to;

    cout << ford_fulkerson(graph, from, to) << endl;
    for (int i = 0; i < graph.size(); ++i) {
        copy(graph[i].begin(), graph[i].end(), ostream_iterator<int>(cout, " "));
        cout << endl;
    }

    return 0;
}

