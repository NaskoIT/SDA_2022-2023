#include <vector>
#include <iostream>

using namespace std;

void dfs(vector<vector<int>> &tree, int node) {
    for (int i = 0; i < tree[node].size(); ++i) {
        int child = tree[node][i];
        dfs(tree, child);
    }

    cout << node << " ";
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

    dfs(tree, 0);
}