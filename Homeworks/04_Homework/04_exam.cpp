#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;

const string ADD_COMMAND = "add";
const string CHEATING_COMMAND = "gun";
const string REARRANGE_COMMAND = "milen";

struct Node {
public:
    int value;
    Node *next;
    Node *previous;

    Node(int value) {
        this->value = value;
        this->next = nullptr;
        this->previous = nullptr;
    }
};

class List {
public:
    Node *head;
    Node *tail;
    Node *middle;
    int size;

    List() {
        size = 0;
        this->head = nullptr;
        this->tail = nullptr;
        this->middle = nullptr;
    }

    void push_back(int value) {
        Node *node = new Node(value);
        if (size == 0) {
            this->head = node;
            this->middle = this->head;
        } else {
            this->tail->next = node;
            node->previous = this->tail;
            if (size % 2 != 0) {
                this->middle = this->middle->next;
            }
        }

        this->tail = node;
        size++;
    }

    int pop_back() {
        if (size == 0) {
            throw logic_error("There are no enough elements in the list!");
        }

        Node *node = this->tail;
        int value = node->value;
        if (size == 1) {
            this->head = nullptr;
            this->tail = nullptr;
            this->middle = nullptr;
        } else {
            this->tail = this->tail->previous;
            this->tail->next = nullptr;
            if (size % 2 == 0) {
                this->middle = this->middle->previous;
            }

            node->previous = nullptr;
        }

        delete node;
        size--;
        return value;
    }

    void reArrange() {
        if (size < 2) {
            return;
        }

        Node *node = this->middle;
        Node *oldTail = this->tail;
        this->tail->next = this->head;
        this->head->previous = this->tail;
        this->tail = node->previous;
        this->tail->next = nullptr;


        if (size % 2 == 0) {
            this->middle = this->head;
        } else {
            this->middle = oldTail;
        }

        this->head = node;
        this->head->previous = nullptr;
    }
};

int main() {
    int n;
    cin >> n;

    List notes;
    for (int i = 0; i < n; ++i) {
        string command;
        cin >> command;
        if (command == ADD_COMMAND) {
            int number;
            cin >> number;
            notes.push_back(number);
        } else if (command == CHEATING_COMMAND) {
            notes.pop_back();
        } else if (command == REARRANGE_COMMAND) {
            notes.reArrange();
        }
    }

    cout << notes.size << endl;

    Node *current = notes.head;
    while (current) {
        cout << current->value << " ";
        current = current->next;
    }
}