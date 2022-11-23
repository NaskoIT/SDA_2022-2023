#include <iostream>
#include <set>

using namespace std;

struct PairComparator {
    bool operator()(const pair<int, char> &first, const pair<int, char> &second) const {
        return first.second < second.second;
    }
};

int main() {
    set<int> s;
    s.insert(2);
    s.insert(15);
    s.insert(25);
    s.insert(1);
    s.insert(10);
    s.insert(20);
    s.insert(8);
    s.insert(8);

    int size = s.size();
    cout << "Size: " << size << endl;

    s.erase(8);
    cout << "Size after deleting element: " << s.size() << endl;

    if (s.count(10)) {
        cout << "The set contains 10" << endl;
    }
    if (!s.count(8)) {
        cout << "The set doesn't contains 8" << endl;
    }

    set<int>::iterator iterator = s.find(10);
    cout << "All the numbers more than " << *iterator << endl;
    for (auto i = iterator; i != s.end(); ++i) {
        cout << *i << " ";
    }

    cout << endl;

    set<int>::iterator lowerBoundIterator = s.lower_bound(10); // Iterator to the first element >= 10
    cout << *lowerBoundIterator << endl;
    set<int>::iterator lowerBoundSecondIterator = s.lower_bound(11); // Iterator to the first element >= 11
    cout << *lowerBoundSecondIterator << endl;

    auto upperBoundIterator = s.upper_bound(10); // Iterator to the first element > 10
    cout << *upperBoundIterator << endl;
    auto upperBoundSecondIterator = s.upper_bound(24); // Iterator to the first element > 24
    cout << *upperBoundSecondIterator << endl;

    upperBoundIterator--;
    cout << *upperBoundIterator << endl;

    cout << "Iterator over the set" << endl;
    for (auto element : s) {
        cout << element << " ";
    }

    cout << endl;

    cout << "Min element is: " << *s.begin() << endl;
    cout << "Max element is: " << *s.rbegin() << endl;

    cout << "Set in descending order" << endl;
    set<int, greater<int>> descendingSet(s.begin(), s.end());

    for (set<int, greater<int>>::iterator i = descendingSet.begin(); i != descendingSet.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;

    s.clear(); // Remove all the elements

    set<pair<int, char>> map;
    map.insert({1, 'A'});
    map.insert({3, 'C'});
    map.insert({2, 'B'});
    map.insert({6, 'F'});
    map.insert({4, 'D'});
    map.insert({5, 'E'});

    cout << "Set with pair<int, char>" << endl;
    for (auto element : map) {
        cout << element.first << " => " << element.second << endl;
    }

    cout << "Find operation demo" << endl;
    set<pair<int, char>>::iterator pairIterator = map.find({3, 'C'});
    cout << (*pairIterator).first << " => " << (pairIterator->second) << endl;

    cout << "Custom comparator demo: " << endl;
    set<pair<int, char>, PairComparator> comparableSet;
    comparableSet.insert({1, 'A'});
    comparableSet.insert({3, 'C'});
    comparableSet.insert({2, 'B'});
    comparableSet.insert({6, 'F'});
    comparableSet.insert({1, 'a'});
    comparableSet.insert({3, 'c'});
    comparableSet.insert({6, 'f'});

    for (auto element : comparableSet) {
        cout << element.first << " => " << element.second << endl;
    }

    cout << "Multiset demo" << endl;
    multiset<int> multiset;
    for (int i = 0; i < 5; ++i) {
        multiset.insert(i);
        multiset.insert(i + 2);
    }

    for (auto element : multiset) {
        cout << element << " ";
    }

    cout << endl;
}