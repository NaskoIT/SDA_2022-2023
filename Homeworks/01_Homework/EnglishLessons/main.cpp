#include <string>
#include <vector>
#include <iostream>

using namespace std;

int countOccurrences(string word, int targetLength, char targetSymbol) {
    vector<int> targetSymbolIndices;
    for (int i = 0; i < word.length(); ++i) {
        if (word[i] == targetSymbol) {
            targetSymbolIndices.push_back(i);
        }
    }

    if (targetSymbolIndices.size() == 0) {
        return 0;
    }

    int wordOccurrences = targetLength / word.length();
    int symbolOccurrences = wordOccurrences * targetSymbolIndices.size();
    int rest = targetLength % word.length();

    if (rest > 0) {
        for (int i = 0; i < targetSymbolIndices.size(); ++i) {
            if (targetSymbolIndices[i] >= rest) {
                break;
            }

            symbolOccurrences++;
        }
    }

    return symbolOccurrences;
}

int main() {
    string word;
    cin >> word;
    int targetLength;
    cin >> targetLength;
    char targetSymbol;
    cin >> targetSymbol;

    cout << countOccurrences(word, targetLength, targetSymbol) << endl;
}
