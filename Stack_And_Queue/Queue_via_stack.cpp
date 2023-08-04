#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> stackPush;
    std::stack<int> stackPop;

    // Move elements from stackPush to stackPop
    void shiftElements() {
        while (!stackPush.empty()) {
            stackPop.push(stackPush.top());
            stackPush.pop();
        }
    }

public:
    // Push element x to the back of the queue.
    void push(int x) {
        stackPush.push(x);
    }

    // Removes the element from in front of the queue and returns that element.
    int pop() {
        if (stackPop.empty()) {
            shiftElements();
        }
        int frontElement = stackPop.top();
        stackPop.pop();
        return frontElement;
    }

    // Get the front element.
    int peek() {
        if (stackPop.empty()) {
            shiftElements();
        }
        return stackPop.top();
    }

    // Return whether the queue is empty.
    bool empty() {
        return stackPush.empty() && stackPop.empty();
    }
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << "Front element: " << q.peek() << std::endl;

    q.pop();
    std::cout << "Front element after pop: " << q.peek() << std::endl;
    q.pop();
    q.pop();

    std::cout << "Is the queue empty? " << (q.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
