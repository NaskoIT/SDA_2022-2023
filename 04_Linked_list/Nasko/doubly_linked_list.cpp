#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *previous;
    Node *next;

    Node(int value) {
        value = value;
        previous = nullptr;
        next = nullptr;
    }

    Node(int value, Node *next, Node *previous) {
        this->value = value;
        this->next = next;
        this->previous = previous;
    }
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

    int elementsCount;

    Node *goToPosition(int position) {
        if (position < elementsCount - position) {
            int currentPosition = 0;
            Node *current = head;

            while (currentPosition < position) {
                current = current->next;
                currentPosition++;
            }

            return current;
        }

        int currentPosition = elementsCount - 1;
        Node *current = tail;
        while (currentPosition > position) {
            current = current->previous;
            currentPosition--;
        }

        return current;
    }

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        elementsCount = 0;
    }

    void push_back(int number) {
        elementsCount++;

        if (tail == nullptr) {
            head = new Node(number, nullptr, nullptr);
            tail = head;
            return;
        }

        tail->next = new Node(number, nullptr, tail);
        tail = tail->next;
    }

    void push_front(int number) {
        elementsCount++;

        if (head == nullptr) {
            head = new Node(number, nullptr, nullptr);
            tail = head;
            return;
        }

        head = new Node(number, head, nullptr);
    }

    void insert_at(int number, int position) {
        if (position < 0 || position > elementsCount) {
            throw invalid_argument("Index out of range exception.");
        }

        if (position >= elementsCount) {
            push_back(number);
            return;
        }

        if (position == 0) {
            push_front(number);
            return;
        }

        elementsCount++;

        Node *current = goToPosition(position - 1);
        current->next = new Node(number, current->next, current);
        current->next->next->previous = current->next;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }

        elementsCount--;

        Node *temp = head;
        head = head->next;
        head->previous = nullptr;
        delete temp;
    }

    void pop_back() {
        if (tail == nullptr) {
            return;
        }

        elementsCount--;

        tail = tail->previous;
        delete tail->next;
        tail->next = nullptr;
    }

    void remove_at(int position) {
        if (position < 0 || position >= elementsCount) {
            throw invalid_argument("Index out of range exception.");
        }

        if (position == 0) {
            pop_front();
            return;
        }

        if (position == elementsCount - 1) {
            pop_back();
            return;
        }

        elementsCount--;

        Node *current = goToPosition(position - 1);

        Node *temp = current->next;
        current->next = temp->next;
        current->next->previous = current;

        delete temp;
    }

    void reverse() {
        if (elementsCount == 2) {
            swap(head->value, head->next->value);
            return;
        }

        Node *forward = head;
        Node *backward = tail;

        int currentPosition = 0;

        while (currentPosition < elementsCount / 2) {
            swap(forward->value, backward->value);
            forward = forward->next;
            backward = backward->previous;
            currentPosition++;
        }
    }

    int peek_front() {
        return head->value;
    }

    int peek_back() {
        return tail->value;
    }

    int get_at(int position) {
        if (position >= elementsCount || position < 0) {
            throw invalid_argument("Index out of range exception.");
        }

        return goToPosition(position)->value;
    }

    int size() {
        return this->elementsCount;
    }

    string to_string() {
        string result = "[";

        Node *current = head;
        while (current != nullptr) {
            result.append(std::to_string(current->value));

            if (current->next != nullptr) {
                result.append(", ");
            }

            current = current->next;
        }

        result.append("]");

        return result;
    }

    void clear() {
        if (head == nullptr) {
            return;
        }

        Node *temp = head;
        Node *current = head->next;

        while (current != nullptr) {
            delete temp;

            temp = current;
            current = current->next;
        }

        delete temp;
        this->elementsCount = 0;
    }
};

void test() {
    DoublyLinkedList list;

    list.push_front(1);
    list.push_back(5);
    list.insert_at(4, 1);
    list.insert_at(19, 2);
    assert("[1, 4, 19, 5]" == list.to_string());

    list.reverse();
    assert("[5, 19, 4, 1]" == list.to_string());

    list.remove_at(1);
    list.pop_back();
    assert("[5, 4]" == list.to_string());

    assert(2 == list.size());

    list.reverse();
    list.push_front(1);
    list.insert_at(2, 1);
    list.insert_at(3, 2);
    list.push_back(6);

    assert("[1, 2, 3, 4, 5, 6]" == list.to_string());

    assert(3 == list.get_at(2));

    list.pop_front();
    assert(2 == list.peek_front());

    list.pop_back();
    assert(5 == list.peek_back());

    list.clear();
    assert(0 == list.size());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    cout << "All tests ran successfully" << endl;

    return 0;
}