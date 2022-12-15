#include <iostream>
#include <vector>
#include <list>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, list<int> &sortedNodes, int node) {
    visited[node] = true;

    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, visited, sortedNodes, child);
        }
    }

    sortedNodes.push_front(node);
}

void topologicalSort(vector<vector<int>> &graph, list<int> &sortedNodes) {
    vector<bool> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, visited, sortedNodes, i);
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
    }

    list<int> sortedNodes;
    topologicalSort(graph, sortedNodes);

    for (auto sortedNode : sortedNodes) {
        cout << sortedNode << " ";
    }
}