#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int value;
    Node *next = nullptr;

    Node(int value, Node *next = nullptr) {
        this->value = value;
        this->next = next;
    }
};

class List {
private:
    Node *head;
    Node *tail;
public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int number) {
        if (head == nullptr) {
            head = new Node(number);
            tail = head;
        } else {
            tail->next = new Node(number);
            tail = tail->next;
        }
    }

    void push_front(int number) {
        Node *newHead = new Node(number, head);
        head = newHead;

        if (tail == nullptr) {
            tail = head;
        }
    }

    void print() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }

    void insert(int number, int position) {
        if (position == 0) {
            push_front(number);
            return;
        } else if (head == nullptr) {
            throw std::out_of_range("Invalid insert index, list is empty");
        }

        Node *current = head;
        Node *previous = nullptr;
        for (int i = 0; i < position; i++) {
            if (current != nullptr) {
                previous = current;
                current = current->next;
            } else {
                throw std::out_of_range("Cannot insert in invalid position");
            }
        }

        previous->next = new Node(number, current);

        if (tail == previous) {
            tail = previous->next;
        }
    }

    void pop_front() {
        Node *temp;
        temp = head;

        if (head != nullptr) {
            if (head == tail) {
                tail = nullptr;
            }

            head = head->next;
            delete temp;
        }
    }

    void pop_back() {
        Node *current;
        Node *previous;
        current = head;

        while (current != tail) {
            previous = current;
            current = current->next;
        }

        tail = previous;
        previous->next = nullptr;
        delete current;
    }

    void remove(int position) {
        if (position == 0) {
            pop_front();
            return;
        } else if (head == nullptr) {
            throw out_of_range("Invalid remove index, list is empty");
        }

        Node *current = head;
        Node *previous = nullptr;
        for (int i = 0; i < position; i++) {
            if (current->next != nullptr) {
                previous = current;
                current = current->next;
            } else {
                throw std::out_of_range("Cannot insert in invalid position");
            }
        }

        previous->next = current->next;

        if (tail == current) {
            tail = previous;
        }

        delete current;
    }

    bool search(int number) {
        Node *current = head;
        while (current != nullptr) {
            if (current->value == number) {
                return true;
            }

            current = current->next;
        }

        return false;
    }

    int peek_front() {
        if (head != nullptr) {
            return head->value;
        } else {
            throw std::out_of_range("List is empty, cannot peek_front()");
        }
    }

    int peek_back() {
        if (tail != nullptr) {
            return tail->value;
        } else {
            throw std::out_of_range("List is empty, cannot peek_back()");
        }
    }

    int getAt(int position) {
        if (head == nullptr) {
            throw std::out_of_range("List is empty, cannot get from it");
        }

        Node* current = head;
        for (int i = 0; i < position; i++) {
            if (current->next != nullptr) {
                current = current->next;
            } else {
                throw std::out_of_range("Cannot get from list, no such position");
            }
        }

        return current->value;
    }
};

int main() {
    List list;
    list.push_back(2);
    list.push_front(0);
    list.insert(1, 1);

    cout << list.getAt(1) << endl;

    list.print();

    list.pop_back();
    list.pop_front();

    list.print();

    for (int i = 2; i < 10; ++i) {
        list.push_back(i);
    }

    list.print();

    list.pop_back();
    cout << list.peek_back() << endl;
    list.pop_front();
    cout << list.peek_front() << endl;

    cout << list.search(3) << endl;
    list.remove(1);
    cout << list.search(3) << endl;
}