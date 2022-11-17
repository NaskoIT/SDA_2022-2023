#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct DescendingIntegerComparator {
    bool operator()(const int x, const int y) const {
        return x < y;
    }
};

struct Node {
public:
    int value;
    int x;
    int y;
    Node *left;
    Node *right;
    bool isVisible;

    Node(int value) {
        this->value = value;
        this->x = 0;
        this->y = 0;
        left = nullptr;
        right = nullptr;
        isVisible = false;
    }

    Node(int value, int x, int y) {
        this->value = value;
        this->x = x;
        this->y = y;
        left = nullptr;
        right = nullptr;
        isVisible = false;
    }
};

void buildTree(vector<Node *> &nodes) {
    for (int i = 0; i < nodes.size(); ++i) {
        int leftNodeValue;
        cin >> leftNodeValue;
        int rightNodeValue;
        cin >> rightNodeValue;

        Node *parent = nodes[i];

        if (leftNodeValue > -1) {
            parent->left = nodes[leftNodeValue];
            nodes[leftNodeValue]->x = parent->x - 1;
            nodes[leftNodeValue]->y = parent->y - 1;
        }

        if (rightNodeValue > -1) {
            parent->right = nodes[rightNodeValue];
            nodes[rightNodeValue]->x = parent->x + 1;
            nodes[rightNodeValue]->y = parent->y - 1;
        }
    }
}

void markNodesVisibility(Node *root, map<int, Node *, DescendingIntegerComparator> &nodesByXCoordinate) {
    if (root == nullptr) {
        return;
    }

    if (nodesByXCoordinate.count(root->x)) {
        Node *oldNode = nodesByXCoordinate[root->x];
        if (oldNode->y < root->y) {
            oldNode->isVisible = false;
            root->isVisible = true;
            nodesByXCoordinate[root->x] = root;
        }
    } else {
        nodesByXCoordinate[root->x] = root;
        root->isVisible = true;
    }

    markNodesVisibility(root->left, nodesByXCoordinate);
    markNodesVisibility(root->right, nodesByXCoordinate);
}

int main() {
    int n;
    cin >> n;

    vector<Node *> nodes(n);
    nodes[0] = new Node(0, 0, 0);

    for (int i = 1; i < n; ++i) {
        nodes[i] = new Node(i);
    }

    buildTree(nodes);

    map<int, Node *, DescendingIntegerComparator> nodesByXCoordinate;

    markNodesVisibility(nodes[0], nodesByXCoordinate);

    for (auto kvp : nodesByXCoordinate) {
        cout << kvp.second->value << " ";
    }
}