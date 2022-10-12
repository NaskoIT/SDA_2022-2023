#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int charToNumber(char symbol) {
    if (symbol >= '0' && symbol <= '9') {
        return symbol - 47;
    } else if (symbol >= 'A' && symbol <= 'Z') {
        return symbol - 28;
    } else if (symbol >= 'a' && symbol <= 'z') {
        return symbol - 86;
    }

    return 0;
}

char intToChar(int number) {
    if (number >= 1 && number <= 10) {
        return (char) (number + 47);
    } else if (number >= 11 && number <= 36) {
        return (char) (number + 86);
    } else if (number >= 37 && number <= 62) {
        return (char) (number + 28);
    }

    return '0';
}

bool comparator(char first, char second) {
    return charToNumber(first) < charToNumber(second);
}

int main() {
    int n;
    cin >> n;
    string input;
    cin >> input;

    vector<int> players(n);
    for (int i = 0; i < input.length(); i++) {
        players[i] = charToNumber(input[i]);
    }

    sort(players.begin(), players.end());

    for (int i = 0; i < players.size(); i++) {
        cout << intToChar(players[i]);
    }

    cout << endl;
}