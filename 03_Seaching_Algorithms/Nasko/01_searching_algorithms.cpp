#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int NOT_FOUND = -1;

bool linearSearch(int array[], int length, int target) {
    for (int i = 0; i < length; i++) {
        if (array[i] == target) {
            return true;
        }
    }

    return false;
}

bool binarySearch(int* array, int target, int start, int end) {
    if(start > end) {
        return false;
    }

    int middle = (start + end) / 2;
    if(array[middle] == target) {
        return true;
    }
    else if(array[middle] > target) {
        binarySearch(array, target, start, middle - 1);
    }
    else if(array[middle] < target) {
        binarySearch(array, target, middle + 1, end);
    }

    return false;
}

int binarySearch(vector<int>& nums, int target, int start, int end) {
    if(start > end) {
        return NOT_FOUND;
    }

    int middle = (start + end) / 2;
    if(nums[middle] == target) {
        return middle;
    }
    else if(nums[middle] > target) {
        binarySearch(nums, target, start, middle - 1);
    }
    else if(nums[middle] < target) {
        binarySearch(nums, target, middle + 1, end);
    }

    return NOT_FOUND;
}

int binarySearch(vector<int>& nums, int target) {
    return binarySearch(nums, target, 0, nums.size());
}

int main() {
}