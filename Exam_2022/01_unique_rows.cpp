#include <iostream>
#include <string>
#include <map>

using namespace std;

const char DELIMITER = '-';

int main() {
    int n, m;
    cin >> n >> m;

    map<string, int> uniqueRows;
    for (int i = 0; i < n; ++i) {
        string row = "";
        for (int j = 0; j < m; ++j) {
            int number;
            cin >> number;
            row += number + DELIMITER;
        }

        uniqueRows[row]++;
    }

    int result = 0;
    for (auto &kvp : uniqueRows) {
        if (kvp.second == 1) {
            result++;
        }
    }

    cout << result;
}