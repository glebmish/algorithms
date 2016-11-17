#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

typedef vector<vector<int>> Graph;

void dfs_briges(Graph &graph, vector<bool> &used, vector<int> &time_in, vector<int> &lowest,
                vector<pair<int, int>> &bridges, int &timer, int cur, int parent = -1) {
    used[cur] = true;

    time_in[cur] = lowest[cur] = timer++;

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next) {
        if (*next == parent) continue;

        if (!used[*next]) {
            dfs_briges(graph, used, time_in, lowest, bridges, timer, *next, cur);

            lowest[cur] = min(lowest[cur], lowest[*next]);

            if (time_in[cur] < lowest[*next])
                bridges.push_back(make_pair(cur, *next));
        } else
            lowest[cur] = min(lowest[cur], time_in[*next]);
    }
}

vector<pair<int, int>> find_briges(Graph &graph) {
    vector<int> time_in(graph.size()),
                lowest(graph.size());
    vector<pair<int, int>> bridges;
    int timer = 0;

    vector<bool> used(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i)
        if (!used[i])
            dfs_briges(graph, used, time_in, lowest, bridges, timer, i);

    return bridges;
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

    vector<pair<int, int>> bridges = find_briges(graph);
    for (auto it = bridges.begin(); it < bridges.end(); ++it)
        cout << it->first << " " << it->second << endl;
}

