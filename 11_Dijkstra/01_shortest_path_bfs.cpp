#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int LEVEL_DELIMITER = -1;
const int NOT_FOUND_PATH = -1;

int getShortestPath(int startNode, int endNode, vector<vector<int>> &graph) {
    vector<bool> visited(graph.size(), false);
    visited[startNode] = true;
    queue<int> queue;
    queue.push(startNode);
    queue.push(LEVEL_DELIMITER);
    int level = 0;

    while (!queue.empty()) {
        int currentNode = queue.front();
        queue.pop();

        if (queue.empty()) {
            break;
        }
        if (currentNode == LEVEL_DELIMITER) {
            level++;
            queue.push(LEVEL_DELIMITER);
            continue;
        }
        if (currentNode == endNode) {
            return level;
        }

        for (auto child : graph[currentNode]) {
            if (!visited[child]) {
                visited[child] = true;
                queue.push(child);
            }
        }
    }

    return NOT_FOUND_PATH;
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

    int sourceNode, destinationNode;
    cin >> sourceNode >> destinationNode;

    int pathLength = getShortestPath(sourceNode, destinationNode, graph);
    if (pathLength == NOT_FOUND_PATH) {
        cout << "There is no path between " << sourceNode << " and: " << destinationNode << endl;
    } else {
        cout << pathLength << endl;
    }
}