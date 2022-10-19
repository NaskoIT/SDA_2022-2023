#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_COMPLEXITY = 2 * 1000000000;

int getBestComplexity(vector<int> &complexities, int skill, int start, int end) {
    int maxPossibleComplexity = -1;
    int minBiggerComplexity = MAX_COMPLEXITY;

    while (start <= end) {
        int middle = (start + end) / 2;
        int currentComplexity = complexities[middle];

        if (currentComplexity == skill) {
            return currentComplexity;
        }
        if (currentComplexity >= skill) {
            end = middle - 1;

            if (minBiggerComplexity > currentComplexity) {
                minBiggerComplexity = currentComplexity;
            }
        } else {
            start = middle + 1;

            if (maxPossibleComplexity < currentComplexity) {
                maxPossibleComplexity = currentComplexity;
            }
        }
    }

    if (maxPossibleComplexity == -1) {
        return minBiggerComplexity;
    } else if (minBiggerComplexity == MAX_COMPLEXITY) {
        return maxPossibleComplexity;
    } else if ((skill - maxPossibleComplexity) > (minBiggerComplexity - skill)) {
        return minBiggerComplexity;
    } else if ((skill - maxPossibleComplexity) < (minBiggerComplexity - skill)) {
        return maxPossibleComplexity;
    }

    return maxPossibleComplexity;
}

int main() {
    int themesCount;
    cin >> themesCount;

    int teamsCount;
    cin >> teamsCount;

    vector<int> complexities(themesCount);
    for (int i = 0; i < themesCount; ++i) {
        cin >> complexities[i];
    }

    vector<int> skills(teamsCount);
    for (int i = 0; i < teamsCount; ++i) {
        cin >> skills[i];
    }

    sort(complexities.begin(), complexities.end());

    for (int i = 0; i < skills.size(); ++i) {
        int complexity = getBestComplexity(complexities, skills[i], 0, complexities.size());
        cout << complexity << endl;
    }
}