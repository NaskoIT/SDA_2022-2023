#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Comparator {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) const {
        if (x.first != y.first) {
            return x.first > y.first;
        }

        return x.second < y.second;
    }
};

int main() {
    priority_queue<int> maxHeap;
    maxHeap.push(1);
    maxHeap.push(4);
    maxHeap.push(3);
    maxHeap.push(20);
    maxHeap.push(10);

    cout << "The max element is: " << maxHeap.top() << endl;
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;

    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(10);
    minHeap.push(4);
    minHeap.push(3);
    minHeap.push(20);
    minHeap.push(1);
    cout << "The min element is: " << minHeap.top() << endl;
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    cout << endl;

    priority_queue<pair<char, int>, vector<pair<char, int>>, greater<pair<char, int>>> pairMinHeap;
    pairMinHeap.push({'A', 1});
    pairMinHeap.push({'B', 15});
    pairMinHeap.push({'C', 10});
    pairMinHeap.push({'D', 5});
    cout << "The min element is: " << pairMinHeap.top().first << " => " << pairMinHeap.top().second << endl;
    while (!pairMinHeap.empty()) {
        cout << pairMinHeap.top().first << " => " << pairMinHeap.top().second << endl;
        pairMinHeap.pop();
    }

    cout << endl;

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> comparablePriorityQueue;
    comparablePriorityQueue.push({1, 1});
    comparablePriorityQueue.push({1, 5});
    comparablePriorityQueue.push({1, 4});
    comparablePriorityQueue.push({3, 5});
    comparablePriorityQueue.push({2, 4});
    comparablePriorityQueue.push({2, 3});

    cout << "The max element is: " << comparablePriorityQueue.top().first << " => "
         << comparablePriorityQueue.top().second << endl;
    while (!comparablePriorityQueue.empty()) {
        cout << comparablePriorityQueue.top().first << " => " << comparablePriorityQueue.top().second << endl;
        comparablePriorityQueue.pop();
    }
}