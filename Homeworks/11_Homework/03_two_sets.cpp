#include<iostream>
#include<vector>
#include <unordered_set>
#include <queue>

using namespace std;

const long long MAX_DISTANCE = 9223372036854775807;

struct Edge {
    int to;
    int distance;

    Edge(int to, int distance) {
        this->to = to;
        this->distance = distance;
    }
};

vector<long long> getBestDistance(vector<vector<Edge>> &graph, vector<int> &startNodes) {
    vector<long long> distances(graph.size(), MAX_DISTANCE);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> priorityQueue;

    for (int startNode : startNodes) {
        priorityQueue.push(make_pair(0, startNode));
        distances[startNode] = 0;
    }

    vector<bool> visited(graph.size());

    while (!priorityQueue.empty()) {
        int nearestNode = priorityQueue.top().second;
        long long distanceToCurrent = priorityQueue.top().first;
        priorityQueue.pop();

        if (visited[nearestNode]) {
            continue;
        }

        visited[nearestNode] = true;

        for (Edge child : graph[nearestNode]) {
            int node = child.to;
            long long currentMinDistance = distanceToCurrent + child.distance;

            if (currentMinDistance < distances[node]) {
                distances[node] = currentMinDistance;
                priorityQueue.push(make_pair(currentMinDistance, node));
            }
        }
    }

    return distances;
}

int main() {
    int verticesCount, edgesCount;
    cin >> verticesCount >> edgesCount;

    vector<vector<Edge>> graph(verticesCount, vector<Edge>());

    for (int i = 0; i < edgesCount; ++i) {
        int from, to, distance;
        cin >> from >> to >> distance;
        graph[from].push_back(Edge(to, distance));
        graph[to].push_back(Edge(from, distance));
    }

    int destinationNodesCount;
    cin >> destinationNodesCount;

    vector<int> destinationNodes(destinationNodesCount);
    for (int i = 0; i < destinationNodesCount; ++i) {
        cin >> destinationNodes[i];
    }

    vector<long long> distances = getBestDistance(graph, destinationNodes);

    int queriesCount;
    cin >> queriesCount;
    vector<long long> results;

    for (int i = 0; i < queriesCount; ++i) {
        int startNode;
        cin >> startNode;
        results.push_back(distances[startNode]);
    }

    for (int answer : results) {
        cout << answer << endl;
    }
}