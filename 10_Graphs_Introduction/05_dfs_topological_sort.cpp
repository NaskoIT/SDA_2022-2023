#include <iostream>
#include <vector>
#include <list>

using namespace std;

const int TEMPORARY_VISITED = 1;
const int PERMANENT_VISITED = 2;

void visit(vector<vector<int>> &graph, vector<int> &visited, list<int> &sortedNodes, int node, bool &hasCycle) {
    if (visited[node] == PERMANENT_VISITED) {
        return;
    }
    if (visited[node] == TEMPORARY_VISITED) {
        hasCycle = true;
        return;
    }

    visited[node] = TEMPORARY_VISITED;
    for (auto child : graph[node]) {
        visit(graph, visited, sortedNodes, child, hasCycle);
    }

    visited[node] = PERMANENT_VISITED;
    sortedNodes.push_front(node);
}

bool topologicalSort(vector<vector<int>> &graph, list<int> &sortedNodes) {
    vector<int> visited(graph.size(), 0);
    bool hasCycle = false;

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            visit(graph, visited, sortedNodes, i, hasCycle);

            if (hasCycle) {
                break;
            }
        }
    }

    return !hasCycle;
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
    bool result = topologicalSort(graph, sortedNodes);
    if (result) {
        for (auto sortedNode : sortedNodes) {
            cout << sortedNode << " ";
        }
    } else {
        cout << "There is cycle in the graph" << endl;
    }
}