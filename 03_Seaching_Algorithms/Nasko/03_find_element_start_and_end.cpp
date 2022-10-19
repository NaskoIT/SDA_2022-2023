#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

//-Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//-If target is not found in the array, return[-1, -1].
//
//-Follow up : Could you write an algorithm with O(log n) runtime complexity ?
//
//-Input: nums = [5,7,7,8,8,8,10], target = 8
// -Output: [3, 5]

bool inRange(int index, int n) {
    return index >= 0 && index < n;
}

int main() {
    int target = 8;
    vector<int> collection = {5, 7, 7, 8, 8, 8, 10};

    vector<int>::iterator firstElement = lower_bound(collection.begin(), collection.end(), target);
    int startIndex = firstElement - collection.begin();

    vector<int>::iterator endElement = upper_bound(collection.begin(), collection.end(), target);
    int endIndex = (endElement - collection.begin()) - 1;

    if (inRange(startIndex, collection.size()) &&
        inRange(endIndex, collection.size()) &&
        collection[startIndex] == target &&
        collection[endIndex] == target) {
        cout << startIndex << " " << endIndex << endl;
    } else {
        cout << "-1 -1" << endl;
    }
}