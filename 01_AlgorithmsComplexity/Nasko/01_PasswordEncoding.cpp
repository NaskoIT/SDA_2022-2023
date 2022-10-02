#include <string>
#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;

    string output = "";

    int i = 0;
    while (i < input.length()) {
        char current = input[i];
        int length = 1;

        int j = i + 1;
        while (j < input.length() && input[i] == input[j]) {
            j++;
            length++;
        }

        i += length;
        output += to_string(length) + current;
    }

    cout << output << endl;
}
