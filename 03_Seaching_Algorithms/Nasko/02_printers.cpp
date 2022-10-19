#include <iostream>
#include <vector>

using namespace std;

bool canReachTargetCopies(vector<long long> &printers, long long time, long long targetCopies) {
    long long totalCopies = 0;
    for (auto printer : printers) {
        totalCopies += time / printer;
        if (totalCopies >= targetCopies) {
            return true;
        }
    }

    return false;
}

long long binarySearch(vector<long long> &printers, long long sheetsCount) {
    long long start = 1;
    long long end = 1000000000000000000;
    long long middle = 0;
    long long bestTime = end;

    while (start <= end) {
        middle = (start + end) / 2;
        bool canPrintEnoughCopies = canReachTargetCopies(printers, middle, sheetsCount);
        if (canPrintEnoughCopies) {
            end = middle - 1;

            if (bestTime > middle) {
                bestTime = middle;
            }
        } else {
            start = middle + 1;
        }
    }

    return bestTime;
}

int main() {
    long long sheetsCount;
    cin >> sheetsCount;
    long long printersCount;
    cin >> printersCount;

    vector<long long> printers(printersCount);
    for (long long i = 0; i < printersCount; ++i) {
        cin >> printers[i];
    }

    cout << binarySearch(printers, sheetsCount);
}