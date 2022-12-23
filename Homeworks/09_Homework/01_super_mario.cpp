#include <iostream>
#include <unordered_map>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<unsigned> keys(n);
    for (int i = 0; i < n; i++)
    {
        cin >> keys[i];
    }

    vector<unsigned> doors(n);
    for (int i = 0; i < n; i++)
    {
        cin >> doors[i];
    }

    unordered_map<unsigned, int> existingKeys;
    int brokenDoors = 0;
    for (int i = 0; i < n; i++)
    {
        unsigned key = keys[i];
        unsigned door = doors[i];
        if(existingKeys.count(key) == 0) {
            existingKeys.insert(make_pair(key, 0));
        }

        existingKeys[key]++;

        if (existingKeys.count(door) == 0 || existingKeys[door] == 0) {
            brokenDoors++;
        }
        else {
            existingKeys[door]--;
        }
    }

    cout << brokenDoors;
}