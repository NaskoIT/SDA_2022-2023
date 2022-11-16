#include <iostream>
#include <queue>
#include <vector>

using namespace std;

    // int row, col;
    // for (int i = 0; i < 2; ++i) {
    //     row = col = -1;
    //     cin >> row >> col;

    //     if (row != -1) {
    //         // валидно прочетена гнила абълка
    //     }
    // }

struct Apple {
    int row;
    int col;
    int day;
};

int main() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<vector<bool>> matrix(n);
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i] = vector<bool>(m, false);
    }

    queue<Apple> q;
    int row, col, day = 0, badApples = 0;
    for (int i = 0; i < 2; ++i) {
        row = col = -1;
        cin >> row >> col;

        if (row != -1) {
            q.push(Apple{row - 1, col - 1, day});
            matrix[row - 1][col - 1] = true;
            badApples++;
        }
    }

    const int DIRECTIONS_COUNT = 4;
    int xDirections[DIRECTIONS_COUNT] = {0, 0, 1, -1};
    int yDirections[DIRECTIONS_COUNT] = {1, -1, 0, 0};

    while (day < t) {
        while (!q.empty() && q.front().day == day) {
            for (int i = 0; i < DIRECTIONS_COUNT; ++i) {
                int newRow = q.front().row + xDirections[i];
                int newCol = q.front().col + yDirections[i];
                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    !matrix[newRow][newCol]) {
                    q.push({newRow, newCol, day + 1});
                    matrix[newRow][newCol] = true;
                    badApples++;
                }
            }

            q.pop();
        }

        day++;
    }

    cout << (n * m) - badApples;
}
