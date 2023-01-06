#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cook {
    long workingTime;
    long index;
};

struct Comparator {
    bool operator() (const Cook& x, const Cook& y) const {
        if(x.workingTime == y.workingTime) {
            return x.index > y.index;
        }

        return x.workingTime > y.workingTime;
    }
};

int main() {
    long long pancakesCount, cookersCount;
    cin >> pancakesCount >> cookersCount;

    vector<int> initialCookers(cookersCount);
    for (int i = 0; i < cookersCount; ++i) {
        cin >> initialCookers[i];
    }

    priority_queue<Cook, vector<Cook>, Comparator> pq;
    for (int i = 0; i < cookersCount; ++i) {
        Cook cook = { initialCookers[i], initialCookers[i] };
        pq.push(cook);
    }

    long readyPancakes = 0;
    long time = 0;
    while (!pq.empty() && readyPancakes < pancakesCount) {
        Cook current = pq.top();
        pq.pop();

        if(time < current.workingTime) {
            time = current.workingTime;
        }

        pq.push({current.workingTime + current.index, current.index});

        readyPancakes++;
    }

    cout << time;
}