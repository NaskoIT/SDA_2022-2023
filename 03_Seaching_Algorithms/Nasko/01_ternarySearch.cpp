#include <iostream>
#include <vector>

using namespace std;

bool ternarySearch(vector<int> arr, int target, int start, int end) {
    if (start > end) {
        return false;
    }

    int middle1 = (2 * start + end) / 3;
    int middle2 = (start + 2 * end) / 3;
    if (arr[middle1] == target || arr[middle2] == target) {
        return true;
    }

    if (arr[middle1] > target) {
        return ternarySearch(arr, target, start, middle1 - 1);
    }
    if (arr[middle2] > target) {
        return ternarySearch(arr, target, middle1 + 1, middle2 - 1);
    }

    return ternarySearch(arr, target, middle2 + 1, end);
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int target;
    cin >> target;

    cout << ternarySearch(numbers, target, 0, numbers.size() - 1);
}