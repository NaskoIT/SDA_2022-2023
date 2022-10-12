#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Trainee {
    int identifier;
    double diameter;
    double time;
    double efficiency;
};

bool comparator(Trainee &first, Trainee &second) {
    if (first.efficiency == second.efficiency) {
        return first.diameter > second.diameter;
    }

    return first.efficiency > second.efficiency;
}

void merge(vector<int> &array, int const left, int const mid, int const right) {
    int const subArrayOneLength = mid - left + 1;
    int const subArrayTwoLength = right - mid;

    // Create temp arrays
    int *leftArray = new int[subArrayOneLength];
    int *rightArray = new int[subArrayTwoLength];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOneLength; i++) {
        leftArray[i] = array[left + i];
    }

    for (int j = 0; j < subArrayTwoLength; j++) {
        rightArray[j] = array[mid + 1 + j];
    }

    // Initial index of first sub-array
    int indexOfSubArrayOne = 0;
    // Initial index of second sub-array
    int indexOfSubArrayTwo = 0;
    // Initial index of merged array
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOneLength && indexOfSubArrayTwo < subArrayTwoLength) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }

        indexOfMergedArray++;
    }

    // Copy the remaining elements of left[], if there are any
    while (indexOfSubArrayOne < subArrayOneLength) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwoLength) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is right index of the sub-array of arr to be sorted */
void mergeSort(vector<int> &array, int const begin, int const end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void sortCollection(vector<int> &collection) {
    mergeSort(collection, 0, collection.size() - 1);
}

int main() {
    int n;
    cin >> n;

    vector<Trainee> trainees;
    for (int i = 0; i < n; ++i) {
        Trainee trainee;
        cin >> trainee.diameter;
        cin >> trainee.time;
        trainee.identifier = i + 1;
        trainee.efficiency = (trainee.diameter * trainee.diameter) / trainee.time;

        trainees.push_back(trainee);
    }

    sort(trainees.begin(), trainees.end(), comparator);

    for (Trainee &trainee : trainees) {
        cout << trainee.identifier << " ";
    }

    cout << endl;
}