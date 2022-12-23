#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to;
    int weight;
};

void dijkstra(vector<vector<Edge>> &graph, vector<int> &distances, int startNode) {
    distances = vector<int>(graph.size(), INT32_MAX);
    distances[startNode] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startNode});

    while (!pq.empty()) {
        int current = pq.top().second;
        int distanceToCurrent = pq.top().first;
        pq.pop();

        for (auto const &edge : graph[current]) {
            int newDistance = distanceToCurrent + edge.weight;
            if (newDistance < distances[edge.to]) {
                distances[edge.to] = newDistance;
                pq.push({newDistance, edge.to});
            }
        }
    }
}

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<Edge>> graph(nodes);
    for (int i = 0; i < edges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    vector<int> distances;
    dijkstra(graph, distances, 0);

    for (int i = 0; i < distances.size(); ++i) {
        cout << "Shortest distance from 0 to " << i << " is: " << distances[i] << endl;
    }
}