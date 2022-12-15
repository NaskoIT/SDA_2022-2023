#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

struct ClientCall {
    unsigned long long callingTime;
    unsigned long long duration;
};

bool canProcessClient(ClientCall *call, vector<unsigned long long> &operatorsOccupationTime, int index) {
    return operatorsOccupationTime[index] <= call->callingTime;
}

void processClient(
        ClientCall *call,
        vector<int> &processedCalls,
        vector<unsigned long long> &operatorsOccupationTime,
        int index) {
    processedCalls[index]++;
    operatorsOccupationTime[index] = call->callingTime + call->duration;
}

int getBestOperatorIndex(vector<int> &processedCalls) {
    int bestIndex = 1;

    for (int i = 2; i < processedCalls.size(); ++i) {
        if (processedCalls[i] > processedCalls[bestIndex]) {
            bestIndex = i;
        }
    }

    return bestIndex;
}

int main() {
    int clientsCount;
    cin >> clientsCount;
    int operatorsCount;
    cin >> operatorsCount;

    vector<ClientCall *> calls(clientsCount);

    for (int i = 0; i < clientsCount; ++i) {
        ClientCall *call = new ClientCall;
        cin >> call->callingTime;
        cin >> call->duration;

        calls[i] = call;
    }

    vector<int> processedCalls(operatorsCount + 1);
    vector<unsigned long long> operatorsOccupationTime(operatorsCount + 1);

    for (int i = 0; i < calls.size(); ++i) {
        ClientCall *call = calls[i];
        int targetOperatorIndex = (i + 1) % operatorsCount;
        targetOperatorIndex = targetOperatorIndex == 0 ? operatorsCount : targetOperatorIndex;

        if (canProcessClient(call, operatorsOccupationTime, targetOperatorIndex)) {
            processClient(call, processedCalls, operatorsOccupationTime, targetOperatorIndex);
        } else {
            bool isClientProcessed = false;
            for (int j = targetOperatorIndex + 1; j < processedCalls.size(); ++j) {
                if (canProcessClient(call, operatorsOccupationTime, j)) {
                    processClient(call, processedCalls, operatorsOccupationTime, j);
                    isClientProcessed = true;
                    break;
                }
            }

            if (!isClientProcessed) {
                for (int j = 1; j < targetOperatorIndex; ++j) {
                    if (canProcessClient(call, operatorsOccupationTime, j)) {
                        processClient(call, processedCalls, operatorsOccupationTime, j);
                        break;
                    }
                }
            }
        }
    }

    int bestOperatorIndex = getBestOperatorIndex(processedCalls);
    cout << bestOperatorIndex - 1 << " ";

    for (int j = bestOperatorIndex + 1; j < processedCalls.size(); ++j) {
        if (processedCalls[j] == processedCalls[bestOperatorIndex]) {
            cout << j - 1 << " ";
        }
    }
}
