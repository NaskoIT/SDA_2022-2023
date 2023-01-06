#include <bits/stdc++.h>

using namespace std;


struct Node {
    Node *next;
    int data;
};


class LinkedList {
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~LinkedList() {
        Node *temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) {
        Node *temp = new Node;
        temp->data = value;
        temp->next = nullptr;

        if (head == nullptr and tail == nullptr) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    void print() {
        Node *curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void sumLists(LinkedList &num2) {
        Node *firstPointer = this->head;
        Node *secondPointer = num2.head;

        int addition = 0;
        stack<int> result;
        while (firstPointer != nullptr || secondPointer != nullptr) {
            int firstDigit = firstPointer == nullptr ? 0 : firstPointer->data;
            int secondDigit = secondPointer == nullptr ? 0 : secondPointer->data;
            secondPointer = secondPointer == nullptr ? nullptr : secondPointer->next;
            firstPointer = firstPointer == nullptr ? nullptr : firstPointer->next;

            int sum = firstDigit + secondDigit + addition;
            addition = sum / 10;
            result.push(sum % 10);
        }

        if (addition != 0) {
            result.push(addition);
        }

        while (!result.empty()) {
            cout << result.top();
            result.pop();
        }
    }

private:
    Node *head, *tail;
};

void solve(LinkedList &num1, LinkedList &num2) {
    num1.sumLists(num2);
}

int main() {
    LinkedList num1, num2;

    int size1, size2;
    cin >> size1;
    for (int i = 0; i < size1; i++) {
        int digit;
        cin >> digit;
        num1.add(digit);
    }

    cin >> size2;
    for (int i = 0; i < size2; i++) {
        int digit;
        cin >> digit;
        num2.add(digit);
    }

    solve(num1, num2);
}