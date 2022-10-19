#include <iostream>

using namespace std;

int main() {
    unsigned long long int points;
    cin >> points;

    unsigned long long int bestPresent = 1;
    for (unsigned long long int  i = 1; i < points; i++) {
        unsigned long long int currentPrice = i * i * i;
        if(currentPrice <= points && bestPresent < i) {
            bestPresent = i;
        }
        else if(currentPrice > points) {
            break;
        }
    }

    long presentsCount = 0;

    while (points > 0) {
        for (unsigned  long long int i = bestPresent; i > 0; i--) {
            unsigned long long int currentPrice = i * i * i;
            if(currentPrice > 0 && currentPrice <= points) {
                bestPresent = i;
                points -= currentPrice;
                presentsCount++;
                break;
            }
        }
    }

    cout << presentsCount << endl;
}