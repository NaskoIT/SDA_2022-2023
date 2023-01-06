#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;

    bool operator<(const Edge &edge) const {
        return this->weight < edge.weight;
    }
};

bool edgeComparator(const Edge &first, const Edge &other) {
    return first.weight < other.weight;
}

int findRoot(int node, vector<int> &parents) {
    if (parents[node] == node) {
        return node;
    }

    parents[node] = findRoot(parents[node], parents);
    return parents[node];
}

void kruskal(vector<Edge> &edges, int nodesCount, vector<Edge> &mstEdges) {
    sort(edges.begin(), edges.end());
    vector<int> parents(nodesCount);
    for (int i = 0; i < parents.size(); ++i) {
        parents[i] = i;
    }

    for (auto const &edge : edges) {
        int fromRoot = findRoot(edge.from, parents);
        int toRoot = findRoot(edge.to, parents);
        if (fromRoot != toRoot) {
            mstEdges.push_back(edge);

            parents[fromRoot] = toRoot;
        }
    }
}

int main() {
    int nodes, edgesCount;
    cin >> nodes >> edgesCount;

    vector<Edge> edges;
    for (int i = 0; i < edgesCount; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        edges.push_back({from, to, weight});
    }

    vector<Edge> mstEdges;
    kruskal(edges, nodes, mstEdges);

    cout << "MST edges: " << endl;
    for (auto const &edge : mstEdges) {
        cout << edge.from << " -> " << edge.to << " with weight: " << edge.weight << endl;
    }
}

//9 11
//0 1 4
//0 2 5
//0 3 9
//2 3 20
//2 4 7
//3 4 8
//4 5 12
//6 7 7
//6 8 8
//7 8 10
//1 3 2
//MST edges:
//1 -> 3 with weight: 2
//0 -> 1 with weight: 4
//0 -> 2 with weight: 5
//2 -> 4 with weight: 7
//6 -> 7 with weight: 7
//6 -> 8 with weight: 8
//4 -> 5 with weight: 12