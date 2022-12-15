#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, int sourceNode) {
    vector<bool> visited(graph.size(), false);
    queue<int> queue;
    queue.push(sourceNode);
    visited[sourceNode] = true;

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();
        cout << currentNode << " ";

        for (auto childNode : graph[currentNode]) {
            if (!visited[childNode]) {
                visited[childNode] = true;
                queue.push(childNode);
            }
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

    bfs(graph, 0);
}