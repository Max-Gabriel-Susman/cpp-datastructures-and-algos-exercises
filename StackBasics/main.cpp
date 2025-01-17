#include <stack>
#include <iostream>
using namespace std;

int main() {
    // Declaration: C++ supports multiple implementations but we will be using
    // std::stack. Specify the data type

    std::stack<int> stack; 

    // Pushing Elements:
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Popping Elements. 
    // Note, unlike other languages popping here does not return the popped value
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;
    stack.pop();
    cout << stack.top() << endl;

    if (stack.empty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack is not empty, top is: " << stack.top() << endl;
    }
    
    return 0;
}