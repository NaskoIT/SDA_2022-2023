#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool topologicalSort(vector<vector<int>> &graph, vector<vector<int>> &reversedGraph, vector<int> &sortedNodes) {
    list<int> nodesWithNoIncomingEdges;
    for (int i = 0; i < reversedGraph.size(); i++) {
        if (reversedGraph[i].empty()) {
            nodesWithNoIncomingEdges.push_back(i);
        }
    }

    while (!nodesWithNoIncomingEdges.empty()) {
        int currentNode = nodesWithNoIncomingEdges.front();
        nodesWithNoIncomingEdges.pop_front();
        sortedNodes.push_back(currentNode);

        for (auto childNode : graph[currentNode]) {
            for (int i = 0; i < reversedGraph[childNode].size(); ++i) {
                if (reversedGraph[childNode][i] == currentNode) {
                    reversedGraph[childNode].erase(reversedGraph[childNode].begin() + i);
                    break;
                }
            }

            if (reversedGraph[childNode].empty()) {
                nodesWithNoIncomingEdges.push_back(childNode);
            }
        }
    }

    for (const auto &children : reversedGraph) {
        if (!children.empty()) {
            return false;
        }
    }

    return true;
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;
    vector<vector<int>> graph(nodes);
    vector<vector<int>> reversedGraph(nodes);

    for (int i = 0; i < edges; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        reversedGraph[to].push_back(from);
    }

    vector<int> sortedNodes;
    bool result = topologicalSort(graph, reversedGraph, sortedNodes);
    if (result) {
        for (auto sortedNode : sortedNodes) {
            cout << sortedNode << " ";
        }
    } else {
        cout << "There is cycle in the graph" << endl;
    }
}