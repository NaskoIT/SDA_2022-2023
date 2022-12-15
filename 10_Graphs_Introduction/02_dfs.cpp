#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int node) {
    visited[node] = true;

    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, visited, child);
        }
    }

    cout << node << " ";
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    vector<bool> visited(nodes, false);
    dfs(graph, visited, 0);
}