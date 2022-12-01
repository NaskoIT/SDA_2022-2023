#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> container = {2, 8, 3, 9, 4, 15, 10, 3, 7, 9, 6, 5, 2, 10};
    if (is_heap(container.begin(), container.end())) {
        cout << "The container is heap!" << endl;
    } else {
        cout << "The container is not heap" << endl;
    }

    make_heap(container.begin(), container.end()); // Convert a range in a container to max heap
    // make_heap(container.begin(), container.end(), greater<int>()); // Convert a range in a container to min heap
    if (is_heap(container.begin(), container.end())) {
        cout << "The container is max heap" << endl;
    }

    cout << "The max element is: " << container.front() << endl;

    container.push_back(50);
    push_heap(container.begin(), container.end()); // reorder the elements in the heap
    // push_heap(container.begin(), container.end(), greater<int>()); // reorder the element in min heap

    cout << "The max element after adding 50 is: " << container.front() << endl;

    pop_heap(container.begin(), container.end()); // delete the max element in the heap
    // pop_heap(container.begin(), container.end(), greater<int>()); // delete the min element from the heap

    cout << "The max element after deleting the max element is: " << container.front() << endl;
}