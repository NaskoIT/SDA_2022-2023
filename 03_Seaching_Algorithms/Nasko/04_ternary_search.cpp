#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int ternarySearch(vector<int> arr, int start, int end, int target) {
    if (start > end) {
        return -1;
    }

    int middle1 = start + (end - start) / 3;
    int middle2 = end - (end - start) / 3;

    if (arr[middle1] == target) {
        return middle1;
    }
    if (arr[middle2] == target) {
        return middle2;
    }

    if (arr[middle1] > target) {
        ternarySearch(arr, start, middle1 - 1, target);
    } else if (arr[middle2] < target) {
        ternarySearch(arr, middle2 + 1, end, target);
    } else {
        ternarySearch(arr, middle1 + 1, middle2 - 1, target);
    }

    return -1;
}

int main() {
    int target = 6;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int answer = ternarySearch(arr, 0, arr.size() - 1, target);

    cout << "Index of " << target << " is " << answer << endl;
}