#include<iostream>
#include<vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;
    // node id -> index in the heap
    unordered_map<int, int> searchCollection;
public:
    int count() {
        return heap.size();
    }

    int extractMin() {
        int min = heap[0];
        int last = heap[heap.size() - 1];
        searchCollection[last] = 0;
        heap[0] = last;
        heap.erase(heap.end() - 1);

        if (!heap.empty()) {
            heapifyDown(0);
        }

        searchCollection.erase(min);

        return min;
    }

    int peekMin() {
        return heap[0];
    }

    void enqueue(int element) {
        searchCollection[element] = heap.size();
        heap.push_back(element);
        heapifyUp(heap.size() - 1);
    }

    void heapifyDown(int i) {
        int left = (2 * i) + 1;
        int right = (2 * i) + 2;
        int smallest = i;

        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            int old = heap[i];
            searchCollection[old] = smallest;
            searchCollection[heap[smallest]] = i;
            heap[i] = heap[smallest];
            heap[smallest] = old;
            heapifyDown(smallest);
        }
    }

    void heapifyUp(int i) {
        int parent = (i - 1) / 2;
        while (i > 0 && heap[i] < heap[parent]) {
            int old = heap[i];
            searchCollection[old] = parent;
            searchCollection[heap[parent]] = i;
            heap[i] = heap[parent];
            heap[parent] = old;

            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void decreaseKey(int element) {
        int index = searchCollection[element];
        heapifyUp(index);
    }
};

int main() {
    PriorityQueue priorityQueue;
    priorityQueue.enqueue(10);
    priorityQueue.enqueue(5);
    priorityQueue.enqueue(15);
    priorityQueue.enqueue(25);
    priorityQueue.enqueue(3);
    priorityQueue.enqueue(7);

    cout << priorityQueue.extractMin();
}