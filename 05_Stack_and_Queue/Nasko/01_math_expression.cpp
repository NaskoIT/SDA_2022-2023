#include <iostream>
#include <stack>

using namespace std;

int main() {
    // 1+(2-(2+3)*4/(3+1))*5
    string expression;
    cin >> expression;
    stack<int> stack;
    for (int i = 0; i < expression.length(); i++) {
        if (expression[i] == '(') {
            stack.push(i);
        } else if (expression[i] == ')') {
            int startIndex = stack.top();
            stack.pop();
            string subExpression = expression.substr(startIndex, i - startIndex + 1);
            cout << subExpression << endl;
        }
    }
}