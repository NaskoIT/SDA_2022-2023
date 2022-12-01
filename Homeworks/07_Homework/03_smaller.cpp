#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<int> numbers(n);
    vector<int> output(n);

    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
        output[i] = -1;
    }

    set<pair<int, int>> orderedNumbers;

    for (int i = n - 1; i >= 0; i--) {
        int currentNumber = numbers[i];
        auto pointer = orderedNumbers.insert(make_pair(currentNumber, i)).first;

        pointer++;
        while (pointer != orderedNumbers.end()) {
            if (pointer->first - currentNumber > k) {
                break;
            } else if (pointer->first == currentNumber) {
                pointer++;
            } else {
                int solutionIndex = pointer->second;
                output[solutionIndex] = i;

                auto nextPointer = pointer;
                nextPointer--;

                orderedNumbers.erase(pointer);

                nextPointer++;
                pointer = nextPointer;
            }
        }
    }

    for (int i = 0; i < output.size(); ++i) {
        cout << output[i] << " ";
    }
}