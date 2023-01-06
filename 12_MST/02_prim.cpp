#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

struct EdgeComparator {
    bool operator()(const Edge &first, const Edge &second) const {
        return first.weight > second.weight;
    }
};

void prim(vector<vector<Edge>> &graph, int startNode, set<int> &spanningTreeNodes, vector<Edge> &mst) {
    spanningTreeNodes.insert(startNode);
    priority_queue<Edge, vector<Edge>, EdgeComparator> pq;

    for (auto const &edge : graph[startNode]) {
        pq.push(edge);
    }

    while (!pq.empty()) {
        Edge currentEdge = pq.top();
        pq.pop();

        int otherNode = spanningTreeNodes.count(currentEdge.from) ? currentEdge.to : currentEdge.from;
        if (!spanningTreeNodes.count(otherNode)) {
            mst.push_back(currentEdge);
            spanningTreeNodes.insert(otherNode);
            for (auto const &edge : graph[otherNode]) {
                pq.push(edge);
            }
        }
    }
}

int main() {
    int nodes, edgesCount;
    cin >> nodes >> edgesCount;

    vector<vector<Edge>> graph(nodes);
    for (int i = 0; i < edgesCount; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back({from, to, weight});
        graph[to].push_back({to, from, weight});
    }

    vector<Edge> mstEdges;
    vector<vector<Edge>> msf;
    set<int> spanningTreeNodes;
    for (int i = 0; i < nodes; ++i) {
        if (!spanningTreeNodes.count(i)) {
            prim(graph, i, spanningTreeNodes, mstEdges);
            msf.emplace_back(mstEdges.begin(), mstEdges.end());
            mstEdges.clear();
        }
    }

    cout << "MST forest: " << endl;
    int index = 1;
    for (auto const &mst : msf) {
        cout << "Mst: " << index++ << endl;
        for (auto const &edge : mst) {
            cout << edge.from << " -> " << edge.to << " with weight: " << edge.weight << endl;
        }
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