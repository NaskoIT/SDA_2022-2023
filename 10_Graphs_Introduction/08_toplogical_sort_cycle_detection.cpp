#include <iostream>
#include <vector>
#include <list>
#include <set>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, list<int> &sortedNodes, set<int> &cycleNodes, int node,
         bool &hasCycle) {
    if (hasCycle || cycleNodes.count(node)) {
        hasCycle = true;
        return;
    }
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    cycleNodes.insert(node);
    for (auto child : graph[node]) {
        dfs(graph, visited, sortedNodes, cycleNodes, child, hasCycle);
    }

    if (!hasCycle) {
        cycleNodes.erase(node);
    }

    sortedNodes.push_front(node);
}

bool topologicalSort(vector<vector<int>> &graph, list<int> &sortedNodes, set<int> &cycleNodes) {
    bool hasCycle = false;
    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, visited, sortedNodes, cycleNodes, i, hasCycle);
        }

        if (hasCycle) {
            break;
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
    set<int> cycleNodes;
    bool result = topologicalSort(graph, sortedNodes, cycleNodes);

    if (result) {
        cout << "Topological sorted: ";
        for (auto element : sortedNodes) {
            cout << element << " ";
        }
    } else {
        cout << "There is a cycle: ";
        for (auto element : cycleNodes) {
            cout << element << " ";
        }
    }

    cout << endl;
}