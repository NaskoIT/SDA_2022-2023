#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> strings;
    unordered_map<string, int> occurrences;

    for (int i = 0; i < n; ++i) {
        string input;
        cin >> input;

        if (occurrences.count(input) == 0) {
            occurrences[input] = 0;
        }

        occurrences[input]++;
        strings.push_back(input);
    }

    for (int i = 0; i < strings.size(); ++i) {
        cout << occurrences[strings[i]] << " ";
    }
}
