// https://www.hackerrank.com/contests/practice-4-sda/challenges/welcome-to-the-jungle/problem

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    stack<int> state;
    vector<int> lengths(n);
    lengths[numbers.size() - 1] = 1;
    state.push(numbers[numbers.size() - 1]);

    for (int i = numbers.size() - 2; i >= 0; i--) {
        if (numbers[i] < state.top()) {
            lengths[i] = lengths[i + 1] + 1;
            state.push(numbers[i]);
        } else {
            while (!state.empty() && state.top() <= numbers[i]) {
                state.pop();
            }

            state.push(numbers[i]);
            lengths[i] = state.size();
        }
    }

    int bestIndex = 0;
    int maxLength = lengths[0];
    for (int i = 1; i < n; ++i) {
        if (lengths[i] > maxLength) {
            maxLength = lengths[i];
            bestIndex = i;
        }
    }

    cout << bestIndex << endl;
}