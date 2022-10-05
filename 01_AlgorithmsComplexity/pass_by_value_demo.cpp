#include <iostream>
#include <vector>

using namespace std;

void passByValue(vector<int> test) {
    // copy the vector
    // very slow of the vector has milions of elements
    if (!test.empty()) {
        test[0] = 25;
        cout << "In passByValue func: " << test[0] << endl;
    }
}

void passByReference(vector<int> &test) {
    // do not copy the vector
    // fast if there are milions of elements in the vector
    if (!test.empty()) {
        test[0] = 35;
        cout << "In passByReference func: " << test[0] << endl;
    }
}

int main() {
    vector<int> test;
    test.push_back(10);
    test.push_back(20);

    cout << "Initial value: " << test[0] << endl;
    passByValue(test);
    cout << "After passByValue func invoked: " << test[0] << endl;
    passByReference(test);
    cout << "After pass by reference test: " << test[0] << endl;
}
