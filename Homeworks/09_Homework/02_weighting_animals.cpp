#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;

    vector<unsigned int> animals(n);
    for (int i = 0; i < n; ++i) {
        cin >> animals[i];
    }

    // Dynamic programming solution using sets to store the previous results
    unordered_map<unsigned int, unsigned long long> occurrences;
    unordered_map<unsigned int, unsigned long long> possibleCombinations;
    unsigned long long totalCombinations = 0;

    for (int i = 0; i < animals.size(); ++i) {
        unsigned int currentAnimal = animals[i];
        if (currentAnimal % k == 0) {
            unsigned int previousAnimal = currentAnimal / k;
            totalCombinations += possibleCombinations[previousAnimal];
            possibleCombinations[currentAnimal] += occurrences[previousAnimal];
        }

        occurrences[currentAnimal]++;
    }

    cout << totalCombinations;
}