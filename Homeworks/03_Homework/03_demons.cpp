#include <iostream>
#include <vector>
#include <map>

using namespace std;

int getElementToReplaceIndex(vector<int> &defences, int start, int end, int targetDefence) {
    while ((end - start) > 1) {
        int middle = start + (end - start) / 2;
        if (defences[middle] >= targetDefence) {
            end = middle;
        } else {
            start = middle;
        }
    }

    return end;
}

int getMaxDefeatedDemons(vector<int> &defences) {
    if (defences.empty()) {
        return 0;
    }

    vector<int> increasingDefences(defences.size());
    int length = 1;
    increasingDefences[0] = defences[0];

    for (int i = 1; i < defences.size(); i++) {
        if (defences[i] < increasingDefences[0]) {
            increasingDefences[0] = defences[i];
        } else if (defences[i] > increasingDefences[length - 1]) {
            increasingDefences[length++] = defences[i];
        } else {
            int index = getElementToReplaceIndex(increasingDefences, -1, length - 1, defences[i]);
            increasingDefences[index] = defences[i];
        }
    }

    return length;
}

int main() {
    int demonsCount;
    cin >> demonsCount;

    map<int, int> demons;
    for (int i = 0; i < demonsCount; ++i) {
        int attack;
        int defence;
        cin >> attack >> defence;

        if (demons.count(attack)) {
            if (demons[attack] > defence) {
                demons[attack] = defence;
            }
        } else {
            demons[attack] = defence;
        }
    }

    vector<int> defences(demons.size());
    int index = 0;
    for (pair<int, int> demon : demons) {
        defences[index++] = demon.second;
    }

    cout << getMaxDefeatedDemons(defences) << endl;
}