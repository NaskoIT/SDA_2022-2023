#include <bits/stdc++.h>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }

    Node(int value, Node *next) {
        this->value = value;
        this->next = next;
    }
};

class List {
private:
    Node *head;
    Node *tail;

    int elementsCount;

    Node *goToPosition(int position) {
        int currentPosition = 0;
        Node *currentNode = head;
        while (currentPosition < position) {
            currentNode = currentNode->next;
            currentPosition++;
        }

        return currentNode;
    }

public:
    List() {
        head = nullptr;
        tail = nullptr;
        elementsCount = 0;
    }

    void push_back(int number) {
        elementsCount++;

        if (tail == nullptr) {
            head = new Node(number, nullptr);
            tail = head;
            return;
        }

        tail->next = new Node(number, nullptr);
        tail = tail->next;
    }

    void push_front(int num) {
        elementsCount++;

        if (head == nullptr) {
            head = new Node(num, nullptr);
            tail = head;
            return;
        }

        head = new Node(num, head);
    }

    void insert_at(int number, int position) {
        if (position < 0 || position > elementsCount) {
            throw invalid_argument("Index out of range exception!");
        }

        if (position == elementsCount) {
            push_back(number);
            return;
        }

        if (position == 0) {
            push_front(number);
            return;
        }

        elementsCount++;

        Node *temp = goToPosition(position - 1);
        temp->next = new Node(number, temp->next);
    }

    void pop_front() {
        elementsCount--;

        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void pop_back() {
        elementsCount--;

        Node *temp = goToPosition(elementsCount - 1);

        tail = temp;
        temp = temp->next;

        delete temp;

        tail->next = nullptr;
    }

    void remove_at(int position) {
        if (position >= elementsCount || position < 0) {
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

        Node *currentNode = goToPosition(position - 1);

        Node *temp = currentNode->next;
        currentNode->next = temp->next;

        delete temp;
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

    void reverse() {
        if (elementsCount == 2) {
            swap(head->value, head->next->value);
            return;
        }

        Node *previousNode = head;
        Node *currentNode = head->next;
        Node *nextNode = currentNode->next;

        while (nextNode != nullptr) {
            currentNode->next = previousNode;

            previousNode = currentNode;
            currentNode = nextNode;
            nextNode = nextNode->next;
        }

        currentNode->next = previousNode;
        head->next = nullptr;

        swap(head, tail);
    }

    int size() {
        return elementsCount;
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

        Node *prev = head;
        Node *cur = head->next;

        while (cur != nullptr) {
            delete prev;

            prev = cur;
            cur = cur->next;
        }

        delete prev;
        elementsCount = 0;
    }
};

void test() {
    List list;

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
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    test();

    cout << "Tests ran successfully!" << endl;

    return 0;
}