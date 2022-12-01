#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

vector<int> toBinary(int number) {
    stack<int> result;
    while (number) {
        result.push(number % 2);
        number /= 2;
    }

    vector<int> bits(result.size());
    int index = 0;
    while (!result.empty()) {
        bits[index++] = result.top();
        result.pop();
    }

    return bits;
}

int toBinaryNumber(vector<int> &bits) {
    int size = bits.size();
    int result = 0;
    int multiplier = 1;
    for (int i = size - 1; i >= 0; i--) {
        result += bits[i] * multiplier;
        multiplier *= 10;
    }

    return result;
}

void generate(vector<int> &bits, vector<int> &set, unordered_set<int> &masks, int index) {
    if (index == set.size()) {
        masks.insert(toBinaryNumber(bits));
        return;
    }

    for (int i = 0; i < 2; ++i) {
        int destinationIndex = set[index];
        bits[destinationIndex] = i;
        generate(bits, set, masks, index + 1);
    }
}

int countMasks(vector<int> &numbers) {
    unordered_set<int> masks;

    for (auto item : numbers) {
        vector<int> bits = toBinary(item);
        vector<int> set;
        for (int i = 0; i < bits.size(); ++i) {
            if (bits[i] == 1) {
                set.push_back(i);
            }

            bits[i] = 0;
        }

        generate(bits, set, masks, 0);
    }

    return masks.size();
}

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << countMasks(numbers);
}