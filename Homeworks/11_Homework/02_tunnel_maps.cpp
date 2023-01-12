#include<iostream>
#include<vector>
#include <unordered_set>
#include <queue>

using namespace std;

const long long MAX_DISTANCE = 9223372036854775807;

struct Edge {
    int to;
    int time;
    int weightToLose;

    Edge(int to, int time, int weightToLose) {
        this->to = to;
        this->time = time;
        this->weightToLose = weightToLose;
    }
};

long long getBestDistance(vector<vector<Edge>> &graph, int maxWeight) {
    vector<long long> distances(graph.size(), MAX_DISTANCE);
    int sourceNode = 1;
    int destinationNode = graph.size() - 1;

    distances[sourceNode] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> priorityQueue;
    priorityQueue.push(make_pair(0, sourceNode));
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
            if (child.weightToLose > maxWeight) {
                continue;
            }

            int node = child.to;
            long long currentMinDistance = distanceToCurrent + child.time;

            if (currentMinDistance < distances[node]) {
                distances[node] = currentMinDistance;
                priorityQueue.push(make_pair(currentMinDistance, node));
            }
        }
    }

    return distances[destinationNode];
}

void findBestWeight(vector<vector<Edge>> &graph, int maxPossibleDistance, int start, int end, int &bestWeight) {
    if (start > end) {
        return;
    }

    int middle = (start + end) / 2;
    long long currentDistance = getBestDistance(graph, middle);

    if (currentDistance <= maxPossibleDistance) {
        bestWeight = middle;
        findBestWeight(graph, maxPossibleDistance, start, middle - 1, bestWeight);
    } else if (currentDistance > maxPossibleDistance) {
        findBestWeight(graph, maxPossibleDistance, middle + 1, end, bestWeight);
    }
}

int main() {
    int verticesCount, edgesCount, batteryPower;
    cin >> verticesCount >> edgesCount >> batteryPower;

    vector<vector<Edge>> graph(verticesCount + 1, vector<Edge>());
    int maxWeight = -1;

    for (int i = 0; i < edgesCount; ++i) {
        int from, to, weightToLose, time;
        cin >> from >> to >> weightToLose >> time;

        if (weightToLose > maxWeight) {
            maxWeight = weightToLose;
        }

        graph[from].push_back(Edge(to, time, weightToLose));
    }

    int bestWeight = -1;
    findBestWeight(graph, batteryPower, 1, maxWeight, bestWeight);
    cout << bestWeight;
}