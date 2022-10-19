#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getFirstSmallerElementIndex(vector<int> &numbers, int start, int end, int bound) {
    int index = 0;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (numbers[middle] > bound) {
            end = middle - 1;
        } else {
            start = middle + 1;
            index = middle;
        }
    }

    return index;
}

int getFirstBiggerElementIndex(vector<unsigned long long> &numbers, int start, int end, long long bound) {
    int index = 0;
    while (start <= end) {
        int middle = (start + end) / 2;
        if (numbers[middle] >= bound) {
            end = middle - 1;

            index = middle;
        } else {
            start = middle + 1;
        }
    }

    return index;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numbersCount;
    cin >> numbersCount;
    int queriesCount;
    cin >> queriesCount;

    vector<int> numbers(numbersCount);
    for (int i = 0; i < numbersCount; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    vector<int> results(queriesCount);
    vector<unsigned long long int> sums(numbersCount);

    if (numbersCount > 0) {
        sums[0] = numbers[0];
    }

    for (int i = 1; i < numbersCount; i++) {
        sums[i] = sums[i - 1] + numbers[i];
    }

    for (int i = 0; i < queriesCount; i++) {
        int maxSum;
        cin >> maxSum;
        int maxNumber;
        cin >> maxNumber;

        if (numbersCount == 0) {
            results[i] = 0;
            continue;
        }

        int index = getFirstSmallerElementIndex(numbers, 0, numbersCount - 1, maxNumber);

        long long int difference = sums[index] - maxSum;
        if (difference <= 0) {
            results[i] = index + 1;
        } else {
            int startIndex = getFirstBiggerElementIndex(sums, 0, numbersCount - 1, difference);
            results[i] = index - startIndex;
        }
    }

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << endl;
    }
}