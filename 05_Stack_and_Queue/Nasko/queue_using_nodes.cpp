#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node *next = nullptr;

    Node(int data, Node *previous = nullptr) {
        this->data = data;
        this->next = previous;
    }
};

class Queue {
private:
    Node *front = nullptr;
    Node *back = nullptr;
public:
    Queue() = default;

    void copy(const Queue &source) {
        Node *current = source.front;
        while (current != nullptr) {
            push(current->data);
            current = current->next;
        }
    }

    void clear() {
        while (front != nullptr) {
            Node *previous = front->next;
            delete front;
            front = previous;
        }
    }

    Queue(const Queue &source) {
        copy(source);
    }

    Queue &operator=(const Queue &source) {
        if (this != &source) {
            clear();
            copy(source);
        }

        return *this;
    }

    ~Queue() {
        clear();
    }

    void push(int number) {
        if (isEmpty()) {
            front = new Node(number);
            back = front;
        } else {
            back->next = new Node(number);
            back = back->next;
        }
    }

    void pop() {
        if (!isEmpty()) {
            Node *oldFront = front;
            front = front->next;
            delete oldFront;
        } else {
            throw std::underflow_error("Queue is empty");
        }
    }

    int peek() const {
        if (!isEmpty()) {
            return front->data;
        } else {
            throw std::underflow_error("Queue is empty");
        }
    }

    bool isEmpty() const {
        return front == nullptr;
    }
};

int main() {
    Queue s;
    s.push(1);
    s.push(2);
    s.push(3);

    Queue d(s);
    while (!d.isEmpty()) {
        cout << d.peek();
        d.pop();
    }
}