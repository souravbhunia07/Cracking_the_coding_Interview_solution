#include <iostream>
#include <stack>

// O(N^2)
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

// O(NlogN)
void merge(std::stack<int>& left, std::stack<int>& right, std::stack<int>& result) {
    while (!left.empty() && !right.empty()) {
        if (left.top() < right.top()) {
            result.push(left.top());
            left.pop();
        } else {
            result.push(right.top());
            right.pop();
        }
    }

    while (!left.empty()) {
        result.push(left.top());
        left.pop();
    }

    while (!right.empty()) {
        result.push(right.top());
        right.pop();
    }
}

void mergeSort(std::stack<int>& inputStack) {
    if (inputStack.size() <= 1) {
        return;
    }

    std::stack<int> left, right;
    int size = inputStack.size();
    int middle = size / 2;

    for (int i = 0; i < middle; ++i) {
        left.push(inputStack.top());
        inputStack.pop();
    }

    for (int i = middle; i < size; ++i) {
        right.push(inputStack.top());
        inputStack.pop();
    }

    mergeSort(left);
    mergeSort(right);

    merge(left, right, inputStack);
}

int main() {
    std::stack<int> myStack;
    myStack.push(5);
    myStack.push(2);
    myStack.push(8);
    myStack.push(1);
    myStack.push(3);

    std::cout << "Original Stack: ";
    std::stack<int> printStack = myStack;
    while (!printStack.empty()) {
        std::cout << printStack.top() << " ";
        printStack.pop();
    }
    std::cout << std::endl;

    mergeSort(myStack);

    std::cout << "Sorted Stack: ";
    while (!myStack.empty()) {
        std::cout << myStack.top() << " ";
        myStack.pop();
    }
    std::cout << std::endl;

    return 0;
}
