#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int jumpSearch(vector<int> &arr, int target) {
    int length = arr.size();
    int step = sqrt(length);
    int previous = 0;

    while (arr[min(step, length) - 1] < target) {
        previous = step;
        step *= 2;
        if (previous >= length) {
            return -1;
        }
    }

    while (arr[previous] < target) {
        previous++;
        if (previous == min(step, length)) {
            return -1;
        }
    }

    if (arr[previous] == target) {
        return previous;
    }

    return -1;
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

    cout << jumpSearch(numbers, target);
}