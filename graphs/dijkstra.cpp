#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n^2 + m)

typedef vector<vector<pair<int, int>>> Graph;
#define INF 10000

vector<int> dijkstra(Graph &graph, int from) {
    vector<int> dist(graph.size(), INF);
    dist[from] = 0;

    vector<bool> used(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i) {
        int cur = 0;
        while(used[cur]) ++cur;

        for (int j = cur + 1; j < dist.size(); ++j)
            if (!used[j] && dist[j] < dist[cur])
                cur = j;

        if (dist[cur] == INF) break;

        used[cur] = true;

        for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next)
            dist[next->first] = min(dist[next->first], dist[cur] + next->second);
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n, vector<pair<int, int>>());

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back(make_pair(to, weight));
    }

    int from;
    cin >> from;

    vector<int> pathes = dijkstra(graph, from);
    copy(pathes.begin(), pathes.end(), ostream_iterator<int>(cout, " "));
}

