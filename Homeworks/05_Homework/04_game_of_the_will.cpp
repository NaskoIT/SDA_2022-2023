#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;

    list<int> players;
    vector<list<int>::iterator> pointersToKillers;

    for (int i = 0; i < n; ++i) {
        int player;
        cin >> player;
        players.push_back(player);
    }

    list<int>::iterator current = players.end();
    bool arePlayersReadyForFinal = true;
    while (current != players.begin()) {
        current--;
        list<int>::iterator previous = current;
        previous--;

        if (previous != players.end() && *current > *previous) {
            if (!pointersToKillers.empty() && current == pointersToKillers.back()) {
                pointersToKillers.pop_back();
            }

            pointersToKillers.push_back(previous);

            list<int>::iterator previousPointer = current;
            previousPointer--;
            players.erase(current);
            current = previousPointer;
            current++;

            arePlayersReadyForFinal = false;
        }
    }

    if (arePlayersReadyForFinal) {
        cout << 0;
        return 0;
    }

    int daysToFinal = 1;
    bool hasKilledPlayers = false;
    for (int i = 0; i < pointersToKillers.size(); i++) {
        list<int>::iterator currentKiller = pointersToKillers[i];
        list<int>::iterator nextPointer = currentKiller;
        nextPointer++;

        if (nextPointer != players.end() && *currentKiller < *nextPointer) {
            if (pointersToKillers.size() > 1 && i >= 1 && nextPointer == pointersToKillers[i - 1]) {
                i--;
                pointersToKillers.erase(pointersToKillers.begin() + i);
            }

            players.erase(nextPointer);
            hasKilledPlayers = true;
        }

        if (pointersToKillers.size() - 1 == i) {
            if (hasKilledPlayers) {
                daysToFinal++;
                hasKilledPlayers = false;
                i = -1;
            } else {
                break;
            }

        }
    }

    cout << daysToFinal;
}