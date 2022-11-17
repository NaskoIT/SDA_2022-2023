#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct DescendingIntegerComparator {
    bool operator()(const int x, const int y) const {
        return x > y;
    }
};

struct Node {
public:
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

void buildTree(vector<int> &elements, map<int, Node *, DescendingIntegerComparator> &nodes) {
    for (int i = 0; i < elements.size(); ++i) {
        int currentElement = elements[i];
        Node *parent = nodes[currentElement];

        int leftIndex = 2 * i + 1;
        if (leftIndex < elements.size()) {
            Node *leftNode = new Node(elements[leftIndex]);
            nodes[leftNode->value] = leftNode;
            parent->left = leftNode;
        }

        int rightIndex = 2 * i + 2;
        if (rightIndex < elements.size()) {
            Node *rightNode = new Node(elements[rightIndex]);
            nodes[rightNode->value] = rightNode;
            parent->right = rightNode;
        }
    }
}

Node *getKthNode(int k, map<int, Node *, DescendingIntegerComparator> &nodes) {
    int index = 0;
    Node *kthNode = nullptr;
    for (auto kvp : nodes) {
        if (index >= k) {
            break;
        }

        kthNode = kvp.second;
        index++;
    }

    return kthNode;
}

Node *getLeftMostElement(Node *node) {
    Node *current = node;

    while (current->left != nullptr) {
        current = current->left;
    }

    return current;
}

Node *remove(Node *node, int element) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->value > element) {
        node->left = remove(node->left, element);
    } else if (node->value < element) {
        node->right = remove(node->right, element);
    } else {
        if (node->left == nullptr) {
            return node->right;
        } else if (node->right == nullptr) {
            return node->left;
        }

        Node *leftMostNode = getLeftMostElement(node->right);
        node->value = leftMostNode->value;
        node->right = remove(node->right, leftMostNode->value);
    }

    return node;
}

void printTreeInLevelOrder(Node *root) {
    if (root == nullptr) {
        return;
    }

    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty()) {
        Node *current = queue.front();

        cout << current->value << " ";

        if (current->left != nullptr) {
            queue.push(current->left);
        }
        if (current->right != nullptr) {
            queue.push(current->right);
        }

        queue.pop();
    }
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> elements(n);
    for (int i = 0; i < n; ++i) {
        cin >> elements[i];
    }

    map<int, Node *, DescendingIntegerComparator> nodes;
    Node *root = new Node(elements[0]);
    nodes[root->value] = root;

    buildTree(elements, nodes);

    Node *kthNode = getKthNode(k, nodes);

    if (kthNode == nullptr) {
        return 0;
    }

    root = remove(root, kthNode->value);

    printTreeInLevelOrder(root);
}