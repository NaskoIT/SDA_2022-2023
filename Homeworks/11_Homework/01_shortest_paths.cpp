#include<iostream>
#include<vector>
#include <unordered_set>
#include <queue>

using namespace std;

const long long MAX_DISTANCE = 9223372036854775807;

struct Edge {
    int to;
    long long value;

    Edge(int to, long long value) {
        this->to = to;
        this->value = value;
    }
};

int main() {
    int verticesCount;
    cin >> verticesCount;
    int edgesCount;
    cin >> edgesCount;

    vector<vector<Edge>> graph(verticesCount + 1, vector<Edge>());

    for (int i = 0; i < edgesCount; ++i) {
        int from, to;
        cin >> from >> to;
        long long value;
        cin >> value;
        graph[from].push_back(Edge(to, value));
    }

    vector<long long> possiblePaths(verticesCount + 1, 0);
    vector<long long> distances(verticesCount + 1, MAX_DISTANCE);
    int sourceNode = 1;
    int destinationNode = verticesCount;

    distances[sourceNode] = 0;
    possiblePaths[sourceNode] = 1;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> priorityQueue;
    priorityQueue.push(make_pair(0, sourceNode));
    vector<bool> visited(verticesCount + 1);

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
            long long currentMinDistance = distanceToCurrent + child.value;

            if (currentMinDistance < distances[node]) {
                distances[node] = currentMinDistance;
                possiblePaths[node] = possiblePaths[nearestNode];

                priorityQueue.push(make_pair(currentMinDistance, node));
            } else if (currentMinDistance == distances[node]) {
                possiblePaths[node] += possiblePaths[nearestNode];
                possiblePaths[node] %= 1000000007;
            }
        }
    }

    if (distances[destinationNode] == MAX_DISTANCE) {
        cout << -1 << " " << 0;
        return 0;
    }

    cout << distances[destinationNode] << " " << possiblePaths[destinationNode];
    return 0;
}