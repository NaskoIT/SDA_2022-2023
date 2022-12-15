#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Comparator {
public:
    bool operator()(const pair<unsigned, unsigned> &first, const pair<unsigned, unsigned> &second) {
        return first.first > second.first;
    }
};

int main() {
    int n;
    cin >> n;

    vector<pair<unsigned, unsigned>> queries;
    int start = 0;
    for (int i = 0; i < n; ++i) {
        unsigned duration;
        cin >> duration;
        queries.push_back(make_pair(duration, start));
        start++;
    }

    priority_queue<
            pair<unsigned, unsigned>,
            vector<pair<unsigned, unsigned>>,
            Comparator> queue;

    queue.push(queries[0]);
    vector<unsigned> executionTimes(n);

    int queryIndex = 1;
    unsigned long long totalTime = 0;
    while (!queue.empty()) {
        pair<unsigned, unsigned> currentQuery = queue.top();
        unsigned delay = (totalTime - currentQuery.second) + currentQuery.first;
        totalTime += currentQuery.first;

        executionTimes[currentQuery.second] = delay;
        queue.pop();

        while (queryIndex < queries.size() && queries[queryIndex].second <= totalTime) {
            queue.push(queries[queryIndex]);
            queryIndex++;
        }
    }

    unsigned long long min = executionTimes[0];
    unsigned long long max = executionTimes[0];

    for (int i = 1; i < executionTimes.size(); ++i) {
        if (executionTimes[i] > max) {
            max = executionTimes[i];
        }

        if (executionTimes[i] < min) {
            min = executionTimes[i];
        }
    }

    cout << min << " " << max;
}
