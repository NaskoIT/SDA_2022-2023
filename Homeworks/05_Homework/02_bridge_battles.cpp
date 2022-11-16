#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct Warrior {
    int attack;
    int position;
    bool isAlive;
};

int main() {
    int n;
    cin >> n;

    vector<Warrior *> warriors(n);
    for (int i = 0; i < n; ++i) {
        Warrior *warrior = new Warrior();
        cin >> warrior->attack;
        warrior->position = i;
        warrior->isAlive = true;

        warriors[i] = warrior;
    }

    queue<Warrior *> negatives;
    stack<Warrior *> positives;

    bool hasPositive = false;
    bool hasNegative = false;
    for (int i = 0; i < warriors.size(); ++i) {
        if (warriors[i]->attack < 0) {
            hasNegative = true;
            negatives.push(warriors[i]);

            if (positives.empty()) {
                negatives.pop();
            }

            if (!hasPositive) {
                continue;
            }

            for (int j = i + 1; j < warriors.size(); ++j) {
                if (warriors[j]->attack < 0) {
                    negatives.push(warriors[j]);
                    i++;
                } else {
                    break;
                }
            }

            while (!positives.empty() && !negatives.empty()) {
                Warrior *positive = positives.top();
                Warrior *negative = negatives.front();

                if (positive->attack == abs(negative->attack)) {
                    positive->isAlive = false;
                    negative->isAlive = false;
                    positives.pop();
                    negatives.pop();
                } else if (positive->attack < abs(negative->attack)) {
                    positive->isAlive = false;
                    positives.pop();
                } else {
                    negative->isAlive = false;
                    negatives.pop();
                }

                hasPositive = false;
            }

            while (!negatives.empty()) {
                negatives.pop();
            }
        } else {
            positives.push(warriors[i]);
            hasPositive = true;
        }
    }

    if (!hasNegative) {
        cout << endl;
        return 0;
    }

    bool hasAliveWarriors = false;
    for (int i = 0; i < warriors.size(); ++i) {
        if (warriors[i]->isAlive) {
            hasAliveWarriors = true;
            cout << warriors[i]->attack << " ";
        }
    }

    if (!hasAliveWarriors) {
        cout << endl;
    }
}