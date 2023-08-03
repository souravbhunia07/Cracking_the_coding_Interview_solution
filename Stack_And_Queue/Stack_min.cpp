#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;   // Main stack to store elements.
    stack<int> minElements; // Stack to store minimum elements.

public:
    void push(int x) {
        // Push the element onto the main stack.
        mainStack.push(x);

        // If the minElements stack is empty or the new element is smaller than or equal to the current minimum,
        // push the new element onto the minElements stack to update the current minimum.
        if (minElements.empty() || x <= minElements.top()) {
            minElements.push(x);
        }
    }

    void pop() {
        // If the main stack is empty, return as there is nothing to pop.
        if (mainStack.empty()) {
            return;
        }

        // Pop the top element from the main stack.
        int topElement = mainStack.top();
        mainStack.pop();

        // If the top element was the minimum element, also pop it from the minElements stack.
        if (topElement == minElements.top()) {
            minElements.pop();
        }
    }

    int top() {
        // Return the top element of the main stack.
        return mainStack.top();
    }

    int min() {
        // Return the top element of the minElements stack, which is the current minimum.
        return minElements.top();
    }
};

int main() {
    MinStack minStack;

    minStack.push(3);
    minStack.push(5);
    minStack.push(2);
    minStack.push(7);

    cout << "Current minimum: " << minStack.min() << endl; // Output: 2

    minStack.pop();
    minStack.pop();

    cout << "Current minimum: " << minStack.min() << endl; // Output: 3

    return 0;
}
