#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int value) {
        this->data = value;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode *node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode *node, string sep, ofstream &fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode *node) {
    while (node) {
        SinglyLinkedListNode *temp = node;
        node = node->next;

        free(temp);
    }
}

SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist, int data, int position) {
    SinglyLinkedListNode *newNode = new SinglyLinkedListNode(data);
    if (position == 0) {
        newNode->next = llist;
        return newNode;
    }

    int index = 1;
    SinglyLinkedListNode *previousNode = llist;
    while (index < position) {
        index++;
        previousNode = previousNode->next;
    }

    newNode->next = previousNode->next;
    previousNode->next = newNode;
    return llist;
}

int main() {
    SinglyLinkedList list;
    list.insert_node(1);
    list.insert_node(2);
    list.insert_node(4);
    list.head = insertNodeAtPosition(list.head, 3, 2);
    list.head = insertNodeAtPosition(list.head, 0, 0);

    SinglyLinkedListNode *current = list.head;
    while (current) {
        cout << current->data;

        current = current->next;

        if (current) {
            cout << ", ";
        }
    }
}
