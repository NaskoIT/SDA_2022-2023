#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int NO_PARENT = -1;

void findPaths(vector<vector<int>> &parents, vector<vector<int>> &paths, vector<int> &currentPath, int node) {
    if (node == NO_PARENT) {
        paths.push_back(currentPath);
        return;
    }

    for (auto parent : parents[node]) {
        currentPath.push_back(node);
        findPaths(parents, paths, currentPath, parent);
        currentPath.pop_back();
    }
}

void bfs(vector<vector<int>> &graph, vector<vector<int>> &parents, vector<int> &distances, int node) {
    vector<int> visited(graph.size(), false);
    distances[node] = 0;
    parents[node].push_back(NO_PARENT);
    queue<int> queue;
    queue.push(node);

    while (!queue.empty()) {
        int current = queue.front();
        queue.pop();

        for (auto child : graph[current]) {
            if (distances[child] > distances[current] + 1) {
                distances[child] = distances[current] + 1;
                queue.push(child);

                parents[child].clear();
                parents[child].push_back(current);
            } else if (distances[child] == distances[current] + 1) {
                parents[child].push_back(current);
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

    int startNode, endNode;
    cin >> startNode >> endNode;

    vector<vector<int>> parents(graph.size());
    vector<int> distances(graph.size(), INT32_MAX);
    vector<vector<int>> paths;
    vector<int> currentPath;


    bfs(graph, parents, distances, startNode);
    findPaths(parents, paths, currentPath, endNode);

    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance from: " << startNode << " to: " << i << " is: " << distances[i] << endl;
    }

    cout << "All possible paths" << endl;
    for (auto const &path : paths) {
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] << " ";
        }

        cout << endl;
    }
}