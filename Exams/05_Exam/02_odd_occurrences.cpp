#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> occurrences;
    for (int i = 0; i < n; ++i) {
        int number;
        cin >> number;

        if (occurrences.count(number) == 0) {
            occurrences[number] = 0;
        }

        occurrences[number]++;
    }

    int sum = 0;
    for (auto kvp : occurrences) {
        if (kvp.second % 2 != 0) {
            sum += kvp.first * kvp.second;
        }
    }

    cout << sum;
}
