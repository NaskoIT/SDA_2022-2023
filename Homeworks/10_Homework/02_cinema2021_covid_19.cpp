#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int POSSIBLE_DIRECTIONS = 4;

struct Seat {
    int row;
    int col;
    int visitTime;

    Seat(int row, int col, int visitTime) {
        this->row = row;
        this->col = col;
        this->visitTime = visitTime;
    }
};

bool isInside(int rows, int cols, int row, int col) {
    return row >= 1 && row <= rows && col >= 1 && col <= cols;
}

int main() {
    int rows;
    cin >> rows;
    int cols;
    cin >> cols;
    int filmDuration;
    cin >> filmDuration;
    int infectedStudentsCount;
    cin >> infectedStudentsCount;

    vector<vector<bool>> students(rows);
    for (int i = 0; i < rows; ++i) {
        students[i] = vector<bool>(cols, false);
    }

    queue<Seat *> infectedStudents;
    int totalInfectedStudents = 0;
    for (int i = 0; i < infectedStudentsCount; ++i) {
        int row;
        cin >> row;
        int col;
        cin >> col;
        Seat *seat = new Seat(row, col, 0);
        infectedStudents.push(seat);
        students[row - 1][col - 1] = true;
        totalInfectedStudents++;
    }

    int rowPossibleDirections[POSSIBLE_DIRECTIONS] = {1, 0, -1, 0};
    int colPossibleDirections[POSSIBLE_DIRECTIONS] = {0, 1, 0, -1};

    while (!infectedStudents.empty()) {
        Seat *seat = infectedStudents.front();
        infectedStudents.pop();

        if (seat->visitTime + 1 > filmDuration) {
            break;
        }

        for (int i = 0; i < POSSIBLE_DIRECTIONS; ++i) {
            int newRow = rowPossibleDirections[i] + seat->row;
            int newCol = colPossibleDirections[i] + seat->col;
            if (isInside(rows, cols, newRow, newCol) &&
                !students[newRow - 1][newCol - 1]) {
                infectedStudents.push(new Seat(newRow, newCol, seat->visitTime + 1));
                totalInfectedStudents++;
                students[newRow - 1][newCol - 1] = true;
            }
        }
    }

    cout << (rows * cols) - totalInfectedStudents;
}
