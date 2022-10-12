#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(vector<int> &numbers) {
    for (int i = 0; i < numbers.size() - 1; i++) {
        int minElementIndex = i;
        for (int j = i + 1; j < numbers.size(); j++) {
            if (numbers[j] < numbers[minElementIndex]) {
                minElementIndex = j;
            }
        }

        if (minElementIndex != i) {
            swap(numbers[i], numbers[minElementIndex]);
        }
    }
}

int main() {
    vector<int> numbers = {3, 5, 2, 100, 50, 200, 1};

    selectionSort(numbers);

    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl;
}
