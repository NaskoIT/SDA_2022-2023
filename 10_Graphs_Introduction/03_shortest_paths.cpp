#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, int sourceNode, vector<int> &distances) {
    vector<bool> visited(graph.size(), false);
    queue<int> queue;
    queue.push(sourceNode);
    visited[sourceNode] = true;
    distances[sourceNode] = 0;

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();

        for (auto childNode : graph[currentNode]) {
            if (!visited[childNode]) {
                visited[childNode] = true;
                queue.push(childNode);
                distances[childNode] = distances[currentNode] + 1;
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

    vector<int> distances(nodes, 0);
    bfs(graph, 0, distances);

    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance from 0 to " << i << " is: " << distances[i] << endl;
    }
}