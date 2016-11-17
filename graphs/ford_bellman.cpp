#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n * m)

struct Edge {
    int from,
        to,
        weight;

    Edge(int _from, int _to, int _weight): from(_from), to(_to), weight(_weight) {}
    Edge() {}
};

typedef vector<Edge> Graph;
#define INF 10000

vector<int> ford_bellman(Graph &graph, int n, int from) {
    vector<int> dist(n, INF);
    dist[from] = 0;

    for (int step = 0; step < n - 1; ++step) {
        for (auto edge = graph.begin(); edge != graph.end(); ++edge)
            if (dist[edge->from] < INF)
                dist[edge->to] = min(dist[edge->to], dist[edge->from] + edge->weight);
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(m);

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph.push_back(Edge(from, to, weight));
    }

    int from;
    cin >> from;

    vector<int> pathes = ford_bellman(graph, n, from);
    copy(pathes.begin(), pathes.end(), ostream_iterator<int>(cout, " "));
}

