#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

// O(n + m)

typedef vector<vector<int>> Graph;

void dfs_cut_vertexes(Graph &graph, vector<bool> &used, vector<int> &time_in, vector<int> &lowest,
                      vector<int> &cut_vertexes, int &timer, int cur, int parent = -1) {
    used[cur] = true;

    time_in[cur] = lowest[cur] = timer++;
    int child_count = 0;

    for (auto next = graph[cur].begin(); next < graph[cur].end(); ++next) {
        if (*next == parent) continue;

        if (!used[*next]) {
            dfs_cut_vertexes(graph, used, time_in, lowest, cut_vertexes, timer, *next, cur);

            lowest[cur] = min(lowest[cur], lowest[*next]);

            if (time_in[cur] <= lowest[*next] && parent != -1)
                cut_vertexes.push_back(cur);

            ++child_count;
        } else
            lowest[cur] = min(lowest[cur], time_in[*next]);
    }

    if (parent == -1 && child_count > 1)
        cut_vertexes.push_back(cur);
}

vector<int> find_cut_vertexes(Graph &graph) {
    vector<int> time_in(graph.size()),
                lowest(graph.size()),
                cut_vertexes;
    int timer = 0;

    vector<bool> used(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i)
        if (!used[i])
            dfs_cut_vertexes(graph, used, time_in, lowest, cut_vertexes, timer, i);

    return cut_vertexes;
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

    vector<int> cut_vertexes = find_cut_vertexes(graph);
    copy(cut_vertexes.begin(), cut_vertexes.end(), ostream_iterator<int>(cout, " "));
}

