#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    unsigned long long start;
    unsigned long long duration;
};

class TaskComparator {
public:
    bool operator()(const Task *first, const Task *second) {
        return first->duration > second->duration;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Task *> tasks(n);
    int start = 0;
    for (int i = 0; i < n; ++i) {
        Task *task = new Task;
        cin >> task->duration;
        task->start = start;
        start++;

        tasks[i] = task;
    }

    priority_queue<Task *, vector<Task *>, TaskComparator> queue;
    queue.push(tasks[0]);
    vector<unsigned long long> results(n);

    int index = 1;
    unsigned long long time = 0;
    while (!queue.empty()) {
        Task *taskToExecute = queue.top();
        unsigned long long delay = (time - taskToExecute->start) + taskToExecute->duration;
        time += taskToExecute->duration;

        results[taskToExecute->start] = delay;
        queue.pop();

        while (index < tasks.size() && tasks[index]->start <= time) {
            queue.push(tasks[index]);
            index++;
        }
    }

    unsigned long long min = results[0];
    unsigned long long max = results[0];

    for (int i = 1; i < results.size(); ++i) {
        unsigned long long current = results[i];
        if (current < min) {
            min = current;
        }

        if (current > max) {
            max = current;
        }
    }

    cout << min << " " << max;
}
