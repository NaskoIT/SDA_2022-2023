#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void dfs(vector<vector<int>> &tree, int node) {
    for (int i = 0; i < tree[node].size(); ++i) {
        int child = tree[node][i];
        dfs(tree, child);
    }

    cout << node << " ";
}

void bfs(vector<vector<int>> &tree, int root) {
    queue<int> q;
    q.push(root);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        for (int child: tree[currentNode]) {
            q.push(child);
        }
    }
}

int main() {
    // 0 ... n
    // m
    // 7 6
    // 0 1
    // 0 2
    // 1 3
    // 1 4
    // 1 5
    // 2 6
    int n, m;
    cin >> n >> m;
    vector<vector<int>> tree(n);

    for (int i = 0; i < m; ++i) {
        int target, source;
        cin >> target >> source;
        tree[target].push_back(source);
    }

    cout << "DFS traversal: ";
    dfs(tree, 0);

    cout << endl;
    cout << "BFS traversal: ";
    bfs(tree, 0);
}