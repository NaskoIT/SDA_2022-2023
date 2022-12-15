#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Homework {
    unsigned int index;
    unsigned int submittedOn;
    unsigned int linesOfCode;
};

class HomeworkComparator {
public:
    bool operator()(const Homework *first, const Homework *second) {
        if (first->linesOfCode == second->linesOfCode) {
            return first->submittedOn > second->submittedOn;
        }

        return first->linesOfCode > second->linesOfCode;
    }
};

bool comparator(const Homework *first, const Homework *second) {
    if (first->submittedOn == second->submittedOn) {
        return first->linesOfCode < second->linesOfCode;
    }

    return first->submittedOn < second->submittedOn;
}

unsigned long long int average(vector<unsigned long long int> &collection) {
    unsigned long long int sum = 0;
    for (int i = 0; i < collection.size(); ++i) {
        sum += collection[i];
    }

    return sum / collection.size();
}

int main() {
    int n;
    cin >> n;

    vector<Homework *> homeworks(n);
    for (int i = 0; i < n; ++i) {
        Homework *homework = new Homework;
        homework->index = i;
        cin >> homework->submittedOn;
        cin >> homework->linesOfCode;

        homeworks[i] = homework;
    }

    sort(homeworks.begin(), homeworks.end(), comparator);

    priority_queue<Homework *, vector<Homework *>, HomeworkComparator> queue;
    queue.push(homeworks[0]);
    unsigned long long int time = homeworks[0]->submittedOn;
    vector<unsigned long long int> evaluationTimes;
    int index = 1;

    while (!queue.empty()) {
        Homework *taskToExecute = queue.top();
        time += taskToExecute->linesOfCode;
        unsigned long long int duration = time - taskToExecute->submittedOn;
        evaluationTimes.push_back(duration);
        queue.pop();

        while (index < homeworks.size() && homeworks[index]->submittedOn <= time) {
            queue.push(homeworks[index]);
            index++;
        }

        if (queue.empty() && index < homeworks.size()) {
            queue.push(homeworks[index]);
            time = homeworks[index]->submittedOn;
            index++;
        }
    }

    cout << average(evaluationTimes);
}
