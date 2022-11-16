#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Warrior {
    int attack;
    int position;
    bool isAlive;
};

int main() {
    int n;
    cin >> n;

    int d;
    cin >> d;

    vector<int> numbers(n);
    list<pair<int, int>> state;
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    if (d == 0 || n == 0) {
        cout << 0;
        return 0;
    }

    long long int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (state.empty()) {
            state.push_back({i, numbers[i]});
        } else {
            if (state.back().second < numbers[i]) {
                state.push_back({i, numbers[i]});
            } else {
                while (state.back().second >= numbers[i] && !state.empty()) {
                    state.pop_back();
                }

                state.push_back({i, numbers[i]});
            }
        }

        if (i >= d - 1) {
            sum += state.front().second;

            if (state.front().first + d - 1 <= i) {
                state.pop_front();
            }
        }
    }

    cout << sum;
}