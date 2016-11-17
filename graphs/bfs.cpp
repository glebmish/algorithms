#include <vector>
#include <iostream>
#include <iterator>
#include <queue>
using namespace std;

// O(n + m)

typedef vector<vector<int>> Graph;

void bfs_traverse(Graph &graph, vector<bool> &used, int i) {
    queue<int> q;
    q.push(i);
    used[i] = true;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next)
            if (!used[*next]) {
                q.push(*next);
                used[*next] = true;
            }
    }
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

    bfs_traverse(graph, used, 0);

    copy(used.begin(), used.end(), ostream_iterator<bool>(cout, " "));
}