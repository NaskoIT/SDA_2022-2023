#include <iostream>
#include <vector>

using namespace std;

void *print(int value) {
    cout << value << " ";
}

struct Node {
    int value;
    Node *left;
    Node *right;

    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node *root;

    Node *findElement(int element) {
        Node *current = this->root;

        while (current != nullptr) {
            if (current->value > element) {
                current = current->left;
            } else if (current->value < element) {
                current = current->right;
            } else {
                break;
            }
        }

        return current;
    }

    void preOrderCopy(Node *node) {
        if (node == nullptr) {
            return;
        }

        this->insert(node->value);
        this->preOrderCopy(node->left);
        this->preOrderCopy(node->right);
    }

    Node *insert(int element, Node *node) {
        if (node == nullptr) {
            node = new Node(element);
        } else if (element < node->value) {
            node->left = this->insert(element, node->left);
        } else if (element > node->value) {
            node->right = this->insert(element, node->right);
        }

        return node;
    }

    void range(Node *node, vector<int> &queue, int start, int end) {
        if (node == nullptr) {
            return;
        }

        if (start < node->value) {
            this->range(node->left, queue, start, end);
        }

        if (start <= node->value && end >= node->value) {
            queue.push_back(node->value);
        }
        if (end > node->value) {
            this->range(node->right, queue, start, end);
        }
    }

    void eachInOrder(Node *node, void *action(int)) {
        if (node == nullptr) {
            return;
        }

        this->eachInOrder(node->left, action);
        action(node->value);
        this->eachInOrder(node->right, action);
    }

    Node *deleteMin(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->left == nullptr) {
            return node->right;
        }

        node->left = this->deleteMin(node->left);

        return node;
    }

    Node *getLeftMostNode(Node *root) {
        Node *current = root;
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

            Node *leftMostNode = this->getLeftMostNode(node->right);
            node->value = leftMostNode->value;
            node->right = this->remove(node->right, leftMostNode->value);
        }

        return node;
    }

    Node *deleteMax(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        if (node->right == nullptr) {
            return node->left;
        }

        node->right = this->deleteMax(node->right);
        return node;
    }

    BinarySearchTree(Node *node) {
        this->preOrderCopy(node);
    }

public:
    BinarySearchTree() {
        this->root = nullptr;
    }

    void insert(int element) {
        this->root = insert(element, this->root);
    }

    bool contains(int element) {
        Node *current = this->findElement(element);

        return current != nullptr;
    }

    void eachInOrder(void *action(int)) {
        this->eachInOrder(this->root, action);
    }

    BinarySearchTree *search(int element) {
        Node *current = this->findElement(element);

        return new BinarySearchTree(current);
    }

    void deleteMin() {
        if (this->root == nullptr) {
            return;
        }

        this->root = this->deleteMin(this->root);
    };

    vector<int> range(int start, int end) {
        vector<int> queue;

        this->range(this->root, queue, start, end);

        return queue;
    }

    void remove(int element) {
        if (this->root == nullptr) {
            return;
        }

        this->root = this->remove(this->root, element);
    }

    void deleteMax() {
        if (this->root == nullptr) {
            return;
        }

        this->root = this->deleteMax(this->root);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(8);
    bst.insert(5);
    bst.insert(3);
    bst.insert(6);
    bst.insert(20);
    bst.insert(10);
    bst.insert(9);
    bst.insert(15);

    bst.eachInOrder(print);

    cout << endl << "remove 6 and 10 from the BST" << endl;

    bst.remove(6);
    bst.remove(10);

    bst.eachInOrder(print);
}