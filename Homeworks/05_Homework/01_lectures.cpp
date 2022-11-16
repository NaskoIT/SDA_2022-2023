#include <iostream>
#include <string>

using namespace std;
const int ASCII_CHARACTERS_COUNT = 256;

int main() {
    string input;
    cin >> input;

    int occurrences[ASCII_CHARACTERS_COUNT];
    int letterIndexes[ASCII_CHARACTERS_COUNT];

    for (int i = 0; i < ASCII_CHARACTERS_COUNT; i++) {
        occurrences[i] = 0;
        letterIndexes[i] = -1;
    }

    for (int i = 0; i < input.length(); ++i) {
        char currentLecture = input[i];
        occurrences[currentLecture]++;
        letterIndexes[currentLecture] = i;
    }

    for (int i = 0; i < input.length(); ++i) {
        char currentLecture = input[i];
        if (occurrences[currentLecture] == 1) {
            cout << letterIndexes[currentLecture] << " ";
        }
    }
}