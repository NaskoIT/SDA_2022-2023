#include <iostream>

using namespace std;

// Merges two subarrays of array[].
// First subarray is array[left..mid]
// Second subarray is array[mid+1..right]
void merge(int array[], int const left, int const mid, int const right) {
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
void mergeSort(int array[], int const begin, int const end) {
    if (begin >= end) {
        return;
    }

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is " << endl;
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is" << endl;
    printArray(arr, arr_size);
    return 0;
}