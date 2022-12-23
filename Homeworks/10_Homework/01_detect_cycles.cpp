#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

void detectCycle(
        unordered_map<int, vector<int>> &graph,
        unordered_set<int> &visitedNodes,
        unordered_set<int> &cycleNodes,
        int node,
        bool &hasCycle) {
    if (cycleNodes.count(node) > 0) {
        hasCycle = true;
        return;
    }

    if (visitedNodes.count(node) == 0) {
        visitedNodes.insert(node);
        cycleNodes.insert(node);

        for (auto child : graph[node]) {
            detectCycle(graph, visitedNodes, cycleNodes, child, hasCycle);
        }

        cycleNodes.erase(node);
    }
}

bool hasCycle(unordered_map<int, vector<int>> &hierarchy) {
    unordered_set<int> visitedNodes;
    unordered_set<int> cycleNodes;

    for (const auto &node : hierarchy) {
        bool hasCycle = false;
        detectCycle(hierarchy, visitedNodes, cycleNodes, node.first, hasCycle);
        if (hasCycle) {
            return true;
        }
    }

    return false;
}

int main() {
    int queriesCount;
    cin >> queriesCount;

    for (int i = 0; i < queriesCount; ++i) {
        int edgesCount;
        cin >> edgesCount;
        unordered_map<int, vector<int>> hierarchy;
        bool hasPrintedResult = false;

        for (int j = 0; j < edgesCount; ++j) {
            int from;
            cin >> from;
            int to;
            cin >> to;

            if (from == to) {
                cout << "1 ";
                hasPrintedResult = true;
                break;
            }

            if (hierarchy.count(from) == 0) {
                hierarchy[from] = vector<int>();
            }

            hierarchy[from].push_back(to);
        }

        if (hasPrintedResult) {
            continue;
        }

        cout << hasCycle(hierarchy) << " ";
    }
}
