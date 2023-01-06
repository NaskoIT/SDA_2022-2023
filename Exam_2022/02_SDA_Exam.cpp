#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_DISTANCE = INT32_MAX;
const int WEIGHT = 6;

void bfs(vector<vector<int>> &graph, int startNode, vector<int> &distances) {
    distances = vector<int>(graph.size(), MAX_DISTANCE);
    distances[startNode] = 0;

    queue<int> q;
    q.push(startNode);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (auto child : graph[current]) {
            if (distances[child] > distances[current] + WEIGHT) {
                distances[child] = distances[current] + WEIGHT;
                q.push(child);
            }
        }
    }
}

int main() {
    int queries;
    cin >> queries;
    vector<vector<int>> results;
    for (int q = 0; q < queries; ++q) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> graph(n + 1);
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }

        int startNode;
        cin >> startNode;

        vector<int> distances;
        bfs(graph, startNode, distances);

        vector<int> result;
        for (int j = 1; j < distances.size(); ++j) {
            if (j != startNode) {
                result.push_back(distances[j] == MAX_DISTANCE ? -1 : distances[j]);
            }
        }

        results.push_back(result);
    }

    for (auto &result : results) {
        for (auto r : result) {
            cout << r << " ";
        }

        cout << endl;
    }
}