#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    multiset<unsigned long long> population;
    auto pointer = population.end();
    vector<double> results;
    for (int i = 0; i < n; ++i) {
        unsigned long long temp;
        cin >> temp;
        population.insert(temp);

        if (population.size() % 2 == 0) {
            if (*pointer > temp) {
                --pointer;
            }

            auto copy = pointer;
            copy++;
            double result = (*pointer + *copy) / 2.0;
            results.push_back(result);
        } else {
            if (*pointer <= temp) {
                pointer++;
            }

            results.push_back(*pointer);
        }
    }

    for (int i = 0; i < results.size(); ++i) {
        printf("%.1f\n", results[i]);
    }
}
