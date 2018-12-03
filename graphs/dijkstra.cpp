#include <vector>
#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
using namespace std;

typedef vector<vector<pair<int, int>>> Graph;
#define INF 10000


// O(n^2 + m)
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

// O(n*log(n)+m*log(n)) 
vector<int> dijkstra_with_heap(Graph &graph, int from) {
    vector<int> dist(graph.size(), INF);
    dist[from] = 0;

    priority_queue<pair<int, int>> q;
    q.emplace(0, from);

    while (!q.empty()) {
        pair<int, int> cur = q.top();
        q.pop();

        if (dist[cur.second] != cur.first) {
            continue;
        }

        for (auto next : graph[cur.second]) {
            int newdist = dist[cur.second] + next.second;
            if (newdist < dist[next.first]) {
                dist[next.first] = newdist;
                q.emplace(dist[next.first], next.first);
            }
        }
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

    vector<int> pathes = dijkstra_with_heap(graph, from);
    copy(pathes.begin(), pathes.end(), ostream_iterator<int>(cout, " "));
}

