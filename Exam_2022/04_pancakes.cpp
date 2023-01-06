#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long pancakesCount, cookersCount;
    cin >> pancakesCount >> cookersCount;

    vector<int> initialCookers(cookersCount);
    for (int i = 0; i < cookersCount; ++i) {
        cin >> initialCookers[i];
    }

    long long start = 1;
    long long end = 1e17;
    long long answer = 0;
    while (start <= end) {
        long long middle = (end + start) / 2;

        long long currentPancakes = 0;
        for (int initialCooker : initialCookers) {
            currentPancakes += middle / initialCooker;

            if (currentPancakes >= pancakesCount) {
                break;
            }
        }

        if (currentPancakes >= pancakesCount) {
            answer = middle;
            end = middle - 1;
        } else {
            start = middle + 1;
        }
    }

    cout << answer;
}