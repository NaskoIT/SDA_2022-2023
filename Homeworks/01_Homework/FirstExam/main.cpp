#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NOT_FOUND_INDEX = -1;

int main() {
    string input;
    cin >> input;
    char targetSymbol;
    cin >> targetSymbol;

    vector<int> targetSymbolIndices;
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == targetSymbol) {
            targetSymbolIndices.push_back(i);
        }
    }

    vector<int> distances(input.length());

    int targetSymbolTempIndex = 0;
    int leftTargetSymbolIndex = NOT_FOUND_INDEX;
    int rightTargetSymbolIndex = targetSymbolIndices[targetSymbolTempIndex++];

    for (int i = 0; i < input.length(); ++i) {
        if (input[i] == targetSymbol) {
            leftTargetSymbolIndex = rightTargetSymbolIndex;
            if (targetSymbolTempIndex >= targetSymbolIndices.size()) {
                rightTargetSymbolIndex = NOT_FOUND_INDEX;
            } else {
                rightTargetSymbolIndex = targetSymbolIndices[targetSymbolTempIndex++];
            }
        } else {
            int leftDistance = leftTargetSymbolIndex == NOT_FOUND_INDEX ? input.length() : i - leftTargetSymbolIndex;
            int rightDistance = rightTargetSymbolIndex == NOT_FOUND_INDEX ? input.length() : rightTargetSymbolIndex - i;
            distances[i] = min(leftDistance, rightDistance);
        }
    }

    for (int i = 0; i < distances.size(); ++i) {
        cout << distances[i] << " ";
    }

    cout << endl;
}
