#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &numbers) {
    for (int i = 1; i < numbers.size(); i++) {
        int key = numbers[i];
        int j = i - 1;
        while (j >= 0 && numbers[j] > key) {
            numbers[j + 1] = numbers[j];
            j--;
        }

        numbers[j + 1] = key;
    }
}


int main() {
    vector<int> numbers = {3, 5, 2, 100, 50, 200, 1};

    insertionSort(numbers);

    for (int i = 0; i < numbers.size(); ++i) {
        cout << numbers[i] << " ";
    }

    cout << endl;
}
