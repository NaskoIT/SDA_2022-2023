#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    unsigned int index;
    unsigned int start;
    unsigned int duration;
};

class TaskComparator {
public:
    bool operator()(const Task *first, const Task *second) {
        if (first->duration == second->duration) {
            return first->index > second->index;
        }

        return first->duration > second->duration;
    }
};

bool comparator(const Task *first, const Task *second) {
    if (first->start == second->start) {
        if (first->duration == second->duration) {
            return first->index < second->index;
        }

        return first->duration < second->duration;
    }

    return first->start < second->start;
}

int main() {
    int n;
    cin >> n;

    vector<Task *> tasks(n);
    for (int i = 0; i < n; ++i) {
        Task *task = new Task;
        task->index = i;
        cin >> task->start;
        cin >> task->duration;

        tasks[i] = task;
    }

    sort(tasks.begin(), tasks.end(), comparator);

    priority_queue<Task *, vector<Task *>, TaskComparator> queue;
    queue.push(tasks[0]);

    int index = 1;
    unsigned long long int time = tasks[0]->start;
    vector<int> result;
    while (!queue.empty()) {
        Task *taskToExecute = queue.top();
        time += taskToExecute->duration;
        result.push_back(taskToExecute->index);
        queue.pop();

        while (index < tasks.size() && tasks[index]->start <= time) {
            queue.push(tasks[index]);
            index++;
        }

        if (queue.empty() && index < tasks.size()) {
            queue.push(tasks[index]);
            time = tasks[index]->start;
            index++;
        }
    }

    for (auto item : result) {
        cout << item << " ";
    }
}
