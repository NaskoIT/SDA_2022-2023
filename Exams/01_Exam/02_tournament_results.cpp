#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Team {
    double participants;
    double oponents;
    double score;
    int identifier;
};

bool comparatorFn(Team& first, Team& second) {
    if(first.score == second.score) {
        return first.participants > second.participants;
    }

    return first.score > second.score;
}

int main() {
    int n;
    cin >> n;

    vector<Team> teams;
    for (int i = 0; i < n; ++i) {
        Team team;
        team.identifier = i + 1;
        cin >> team.participants;
        cin >> team.oponents;
        team.score = (team.participants * team.participants) / team.oponents;

        teams.push_back(team);
    }


    sort(teams.begin(), teams.end(), comparatorFn);

    for (int i = 0; i < teams.size(); ++i) {
        cout << teams[i].identifier << " ";
    }
}