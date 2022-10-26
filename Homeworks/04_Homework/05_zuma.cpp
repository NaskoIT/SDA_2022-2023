#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<list<int>::iterator> references;
    list<int> balls;
    list<int>::iterator pointer;
    for (int i = 0; i < n; ++i) {
        int ball;
        cin >> ball;
        balls.push_back(ball);

        if (i == 0) {
            pointer = balls.begin();
        } else {
            pointer++;
        }

        references.push_back(pointer);
    }

    int queriesCount;
    cin >> queriesCount;

    vector<string> output;

    for (int i = 0; i < queriesCount; ++i) {
        int position;
        cin >> position;
        int targetBall;
        cin >> targetBall;

        if (balls.empty()) {
            output.push_back("Game Over");
            continue;
        }

        auto currentBallPointer = references[position];
        currentBallPointer++;
        balls.insert(currentBallPointer, targetBall);
        auto newBallPointer = references[position];
        ++newBallPointer;
        references.push_back(newBallPointer);

        list<int>::iterator startPointer = references[position];
        int totalBallsToCollapse = 0;
        int ballsToCollapse = 0;
        bool shouldRemoveFirst = false;
        while (startPointer != balls.begin() && *startPointer == targetBall) {
            ballsToCollapse++;
            startPointer--;
        }

        if (startPointer == balls.begin() && *startPointer == targetBall) {
            ballsToCollapse++;
            shouldRemoveFirst = true;
        }

        list<int>::iterator endPointer = references[position];
        endPointer++;
        while (endPointer != balls.end() && *endPointer == targetBall) {
            ballsToCollapse++;
            endPointer++;
        }

        if (ballsToCollapse < 3) {
            output.push_back("0");
            continue;
        }

        totalBallsToCollapse = ballsToCollapse;
        list<int>::iterator startCollapsePointer = startPointer;
        list<int>::iterator endCollapsePointer = endPointer;

        if (startPointer == balls.begin() && !shouldRemoveFirst && *startPointer == *endPointer) {
            int rightBallsToCollapse = 1;
            while (endPointer != balls.end() && *endPointer == *startPointer) {
                rightBallsToCollapse++;
                endPointer++;
            }

            if (rightBallsToCollapse >= 3) {
                totalBallsToCollapse += rightBallsToCollapse;
            }
        }

        while (endCollapsePointer != balls.end() &&
               *startCollapsePointer == *endCollapsePointer) {
            targetBall = *endCollapsePointer;
            ballsToCollapse = 0;
            while (endPointer != balls.end() && *endPointer == targetBall) {
                ballsToCollapse++;
                endPointer++;
            }

            while (startPointer != balls.begin() && *startPointer == targetBall) {
                ballsToCollapse++;
                startPointer--;
            }

            if (startPointer == balls.begin() && *startPointer == targetBall) {
                ballsToCollapse++;
                shouldRemoveFirst = true;
            }

            if (ballsToCollapse < 3) {
                break;
            }

            startCollapsePointer = startPointer;
            endCollapsePointer = endPointer;
            totalBallsToCollapse += ballsToCollapse;
        }

        list<int>::iterator startErasePointer = shouldRemoveFirst ? balls.begin() : ++startCollapsePointer;
        balls.erase(startErasePointer, endCollapsePointer);

        output.push_back(to_string(totalBallsToCollapse));
    }

    for (auto line : output) {
        cout << line << endl;
    }

    if (balls.empty()) {
        cout << "-1";
    } else {
        for (int ball : balls) {
            cout << ball << " ";
        }
    }
}