#include <iostream>
#include <stack>

// Function to sort a stack in ascending order
void sortStack(std::stack<int>& originalStack) {
    // Create an additional temporary stack to store elements in sorted order
    std::stack<int> tempStack;

    // Iterate through the elements of the original stack
    while (!originalStack.empty()) {
        // Take the top element from the original stack
        int tmp = originalStack.top();
        originalStack.pop();

        // Move elements from the temporary stack back to the original stack
        // until the correct position for the current element is found
        while (!tempStack.empty() && tempStack.top() > tmp) {
            originalStack.push(tempStack.top());
            tempStack.pop();
        }

        // Insert the current element at its correct position in the temporary stack
        tempStack.push(tmp);
    }

    // After sorting, copy the elements back to the original stack in sorted order
    while (!tempStack.empty()) {
        originalStack.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    std::stack<int> myStack;
    myStack.push(5);
    myStack.push(2);
    myStack.push(8);
    myStack.push(1);
    myStack.push(3);

    std::cout << "Original Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    myStack.push(5);
    myStack.push(2);
    myStack.push(8);
    myStack.push(1);
    myStack.push(3);

    sortStack(myStack);

    std::cout << "Sorted Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
