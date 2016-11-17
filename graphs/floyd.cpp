#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n^3)

typedef vector<vector<int>> Graph;
#define INF 10000

void floyd(Graph &graph) {
    int n = graph.size();

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
}

int main() {
    int n, m;
    cin >> n >> m;

    Graph graph(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i)
        graph[i][i] = 0;

    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from][to] = graph[to][from] = weight;
    }

    floyd(graph);

    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph[i].size(); ++j)
            if (graph[i][j] == INF)
                cout << "i ";
            else
                cout << graph[i][j] << " ";
        cout << endl;
    }

    return 0;
}

