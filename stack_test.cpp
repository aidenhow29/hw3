#include "stack.h"
#include <vector>
#include <stdexcept>
#include <iostream>

using namespace std;

int main(){


    Stack<int> myStack;

    myStack.push(2);
    myStack.push(6);
    myStack.push(2);
    myStack.push(4);
    myStack.push(7);

    myStack.pop();

    cout << myStack.top() << endl;

    





}