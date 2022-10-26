#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
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

int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2) {
    SinglyLinkedListNode *firstListTempNode = head1;
    SinglyLinkedListNode *secondListTempNode = head2;

    while (firstListTempNode) {
        while (secondListTempNode) {
            if (firstListTempNode == secondListTempNode) {
                return firstListTempNode->data;
            }

            secondListTempNode = secondListTempNode->next;
        }

        firstListTempNode = firstListTempNode->next;
        secondListTempNode = head2;
    }

    return -1;
}