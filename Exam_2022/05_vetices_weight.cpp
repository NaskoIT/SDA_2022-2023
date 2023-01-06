#include <iostream>
#include <map>
#include <vector>
#include <set>

using namespace std;

void dfs(map<int, vector<int>> &graph, map<int, long long> &weights, set<int> &visited, int node) {
    visited.insert(node);

    for (auto child : graph[node]) {
        if (!visited.count(child)) {
            dfs(graph, weights, visited, child);
            weights[node] += weights[child];
        }
    }
}

int main() {
    int m, n;
    cin >> m >> n;

    map<int, vector<int>> graph;
    map<int, long long> childWeights;
    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);

        childWeights[from] = from;
        childWeights[to] = to;
    }

    set<int> visited;
    for (auto &kvp : graph) {
        if (!visited.count(kvp.first)) {
            dfs(graph, childWeights, visited, kvp.first);
        }
    }

    vector<long long> res;
    for (int i = 0; i < n; ++i) {
        int node;
        cin >> node;
        res.push_back(childWeights[node] - node);
    }

    for (auto r : res) {
        printf("%lld\n", r);
    }
}