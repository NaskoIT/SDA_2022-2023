#include <iostream>
#include <vector>

using namespace std;

void calculateNodes(vector<vector<int>> &tree, vector<int> &results, vector<bool> &visited, int index);

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n);
    for (int i = 0; i < n; ++i) {
        tree[i] = vector<int>();
    }

    for (int i = 0; i < n - 1; ++i) {
        int node;
        cin >> node;
        int child;
        cin >> child;

        tree[node].push_back(child);
    }

    vector<int> results(n);
    vector<bool> visited(n);
    calculateNodes(tree, results, visited, 0);

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
}

void calculateNodes(vector<vector<int>> &tree, vector<int> &results, vector<bool> &visited, int index) {
    if (visited[index]) {
        return;
    }

    int childrenCount = 0;
    for (int i = 0; i < tree[index].size(); ++i) {
        int currentNode = tree[index][i];
        calculateNodes(tree, results, visited, currentNode);
        childrenCount += results[currentNode] + 1;
    }

    results[index] += childrenCount;
}