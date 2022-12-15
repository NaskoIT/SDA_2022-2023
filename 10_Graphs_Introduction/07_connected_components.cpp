#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, map<int, vector<int>> &connectedComponents, int node,
         int component) {
    visited[node] = true;
    connectedComponents[component].push_back(node);

    for (auto child : graph[node]) {
        if (!visited[child]) {
            dfs(graph, visited, connectedComponents, child, component);
        }
    }
}

void findConnectedComponents(vector<vector<int>> &graph, map<int, vector<int>> &connectedComponents) {
    vector<bool> visited(graph.size(), false);
    int component = 1;
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            connectedComponents[component] = vector<int>();
            dfs(graph, visited, connectedComponents, i, component);
            component++;
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
        graph[to].push_back(from);
    }

    map<int, vector<int>> connectedComponents;
    findConnectedComponents(graph, connectedComponents);

    for (auto kvp : connectedComponents) {
        cout << "Component: " << kvp.first << endl;
        for (auto node : kvp.second) {
            cout << node << " ";
        }

        cout << endl;
    }
}