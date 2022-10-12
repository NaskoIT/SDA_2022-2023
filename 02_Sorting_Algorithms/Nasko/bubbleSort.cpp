#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(vector<int> &arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
    }
}

int main() {
    vector<int> numbers = {3, 5, 2, 100, 50, 200, 1};

    bubbleSort(numbers);

    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl;
}
