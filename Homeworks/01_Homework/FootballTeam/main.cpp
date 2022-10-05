#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

// solution using hash set
int getMissingNumber(int n) {
    set<int> numbers;
    int currentNumber;

    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;

        if (currentNumber > 0) {
            numbers.insert(currentNumber);
        }
    }

    int missingNumber = 1;

    for (int element: numbers) {
        if (element != missingNumber) {
            break;
        }

        missingNumber++;
    }

    return missingNumber;
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    int currentNumber;

    for (int i = 0; i < n; ++i) {
        cin >> currentNumber;

        if (currentNumber > 0) {
            numbers.push_back(currentNumber);
        }
    }

    sort(numbers.begin(), numbers.end());

    int missingNumber = 1;

    // 1 1 2
    for (int element: numbers) {
        if (element == missingNumber) {
            missingNumber++;
        } else if (element > missingNumber) {
            break;
        }
    }

    cout << missingNumber;
}
