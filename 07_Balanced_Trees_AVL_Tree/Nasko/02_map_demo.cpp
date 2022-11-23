#include <iostream>
#include <map>

using namespace std;

struct MapComparator {
    bool operator()(const char &first, const char &second) const {
        return first > second;
    }
};

int main() {
    map<char, int> table;
    table.insert({'A', 5}); // Insert or change using key-value pair
    table.insert({'C', 2});
    table['D'] = 6; // Insert or change by key;
    table['F'] = 1;

    if (table.count('F')) {
        cout << "The map contains F" << endl;
    }

    cout << "Delete F" << endl;
    table.erase('F'); // Remove element by key

    if (!table.count('F')) {
        cout << "The map doesn't contains F" << endl;
    }

    cout << "Iterate over the map" << endl;
    for (auto element : table) {
        cout << element.first << " => " << element.second << endl;
    }

    cout << "Iterate over the map using iterators" << endl;
    for (auto i = table.begin(); i != table.end(); i++) {
        cout << i->first << " => " << (*i).second << endl;
    }

    cout << "Build descending map" << endl;
    map<char, int, greater<char>> descendingMap(table.begin(), table.end());
    for (pair<char, int> kvp : descendingMap) {
        cout << kvp.first << " => " << kvp.second << endl;
    }

    cout << "Custom comparator" << endl;
    map<char, int, MapComparator> comparableMap;
    for (int i = 0; i < 5; ++i) {
        comparableMap.insert({(char) (i + 65), i * 5});
    }

    for (auto kvp : comparableMap) {
        cout << kvp.first << " => " << kvp.second << endl;
    }

    cout << "Multimap demo" << endl;
    multimap<int, int, greater<int>> multimap;
    for (int i = 0; i < 5; ++i) {
        multimap.insert({i + 1, i});
        multimap.insert({i, i * i});
    }

    for (auto kvp : multimap) {
        cout << kvp.first << " => " << kvp.second << endl;
    }
}