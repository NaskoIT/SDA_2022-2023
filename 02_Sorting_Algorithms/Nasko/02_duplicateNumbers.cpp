#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool containsDuplicate(vector<int> &nums) {
    set<int> uniqueNumbers;
    for (int i = 0; i < nums.size(); ++i) {
        uniqueNumbers.insert(nums[i]);
    }

    return nums.size() != uniqueNumbers.size();
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << containsDuplicate(nums) << endl;

    vector<int> uniqueNums = {1, 2, 3};
    cout << containsDuplicate(uniqueNums) << endl;
}
