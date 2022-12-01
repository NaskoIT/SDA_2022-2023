#include <iostream>
#include <set>

using namespace std;

int getXOR(int x, int y) {
    return x ^ y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> set;
    set.insert(0);

    int minNumber = INT32_MAX;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (set.count(num) == 1) {
            printf("%d\n", minNumber);
            continue;
        }

        auto pointer = set.insert(num);
        auto previousPointer = pointer.first;
        previousPointer--;
        if (previousPointer != set.end()) {
            int previousXorResult = getXOR(*previousPointer, num);
            if (previousXorResult < minNumber) {
                minNumber = previousXorResult;
            }
        }

        auto nextPointer = pointer.first;
        nextPointer++;

        if (nextPointer != set.end()) {
            int nextXorResult = getXOR(*nextPointer, num);
            if (nextXorResult < minNumber) {
                minNumber = nextXorResult;
            }
        }

        printf("%d\n", minNumber);
    }
}