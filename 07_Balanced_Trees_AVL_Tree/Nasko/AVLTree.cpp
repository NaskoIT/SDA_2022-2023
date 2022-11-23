// reference: https://kukuruku.co/post/avl-trees/

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    int height;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        this->height = 1;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class AVLTree {
private:
    Node *root;

    int getHeight(Node *node) {
        return node == nullptr ? 0 : node->height;
    }

    int calculateBalanceFactor(Node *node) {
        return getHeight(node->right) - getHeight(node->left);
    }

    void fixHeight(Node *node) {
        int leftChildHeight = getHeight(node->left);
        int rightChildHeight = getHeight(node->right);
        node->height = max(leftChildHeight, rightChildHeight) + 1;
    }

    Node *rotateRight(Node *node) {
        Node *temp = node->left;
        node->left = temp->right;
        temp->right = node;

        fixHeight(node);
        fixHeight(temp);

        return temp;
    }

    Node *rotateLeft(Node *node) {
        Node *temp = node->right;
        node->right = temp->left;
        temp->left = node;

        fixHeight(node);
        fixHeight(temp);

        return temp;
    }

    Node *balance(Node *node) {
        fixHeight(node);
        if (calculateBalanceFactor(node) == 2) {
            if (calculateBalanceFactor(node->right) < 0)
                node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        if (calculateBalanceFactor(node) == -2) {
            if (calculateBalanceFactor(node->left) > 0)
                node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        return node;
    }

    Node *insert(Node *node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return balance(node);
    }

    Node *findMin(Node *node) {
        return node->left != nullptr ? findMin(node->left) : node;
    }

    Node *removeMin(Node *node) {
        if (node->left == nullptr) {
            return node->right;
        }

        node->left = removeMin(node->left);

        return balance(node);
    }

    Node *remove(Node *node, int value) {
        if (node == nullptr) {
            return nullptr;
        }

        if (value < node->value) {
            node->left = remove(node->left, value);
        } else if (value > node->value) {
            node->right = remove(node->right, value);
        } else {
            Node *left = node->left;
            Node *right = node->right;
            delete node;

            if (right == nullptr) {
                return left;
            }

            Node *min = findMin(right);
            min->right = removeMin(right);
            min->left = left;

            return balance(min);
        }

        return balance(node);
    }

    void inOrder(Node *node, void (*print)(int)) {
        if (node == nullptr) {
            return;
        }

        inOrder(node->left, print);
        print(node->value);
        inOrder(node->right, print);
    }

public:
    AVLTree() {
        this->root = nullptr;
    }

    void insert(int key) {
        this->root = insert(this->root, key);
    }

    void remove(int key) {
        this->root = remove(this->root, key);
    }

    void inOrder(void (*print)(int)) {
        inOrder(this->root, print);
    }
};

void printToConsole(int value) {
    cout << value << " ";
}

int main() {
    AVLTree tree;

    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(-5);
    tree.insert(-10);
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);
    tree.insert(16);
    tree.insert(17);
    tree.insert(18);

    tree.inOrder(printToConsole);

    cout << endl;

    tree.remove(25);
    tree.remove(15);
    tree.remove(16);
    tree.remove(17);
    tree.remove(-5);
    tree.remove(-10);
    tree.remove(3);
    tree.remove(2);

    tree.inOrder(printToConsole);
}