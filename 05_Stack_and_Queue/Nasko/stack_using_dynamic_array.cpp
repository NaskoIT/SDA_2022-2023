#include <iostream>
#include <stdexcept>

using namespace std;

class Stack {
private:
    int capacity;
    int* data;
    // index of the last element
    int top;
public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->data = new int[capacity];
        top = -1;
    }

    void copy(const Stack& source) {
        this->capacity = source.capacity;
        this->data = new int[capacity];
        this->top = source.top;

        for (int i = 0; i <= source.top; i++) {
            this->data[i] = source.data[i];
        }
    }

    void clear() {
        delete[] this->data;
        this->data = nullptr;
        top = -1;
        capacity = 0;
    }

    Stack(const Stack& source) {
        copy(source);
    }

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            clear();
            copy(other);
        }

        return *this;
    }

    ~Stack() {
        clear();
    }

    void push(int number) {
        if (top < capacity - 1) {
            top++;
            data[top] = number;
        } else {
            throw std::overflow_error("Stack is full");
        }
    }

    void pop() {
        if (top > -1) {
            top--;
        } else {
            throw std::underflow_error("Stack is empty");
        }
    }

    int peek() const {
        if (top > -1) {
            return data[top];
        } else {
            throw std::underflow_error("Stack is empty");
        }
    }

    bool isEmpty() const {
        return top == -1;
    }
};

int main() {
    Stack s(3);
    s.push(1);
    s.push(2);
    s.push(3);
    // s.push(4); // overflow

    cout << s.peek(); // 3
    s.pop();
    cout << s.peek(); // 2
    s.pop();
    cout << s.peek(); // 1
    s.pop();
    // s.pop(); // underflow
    
    cout << s.isEmpty(); // 1 = true, is indeed empty
}