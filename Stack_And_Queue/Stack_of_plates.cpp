#include <iostream>
#include <vector>
using namespace std;

class SetOfStacks {
private:
    int capacity;
    vector<vector<int>> stacks;
    int current_stack;

public:
    SetOfStacks(int capacity) : capacity(capacity), current_stack(0) {
        stacks.push_back(vector<int>());
    }

    void push(int item) {
        if (stacks[current_stack].size() == capacity) {
            stacks.push_back(vector<int>());
            current_stack++;
        }
        stacks[current_stack].push_back(item);
    }

    int pop() {
        if (stacks[current_stack].empty()) {
            if (current_stack > 0) {
                current_stack--;
            } else {
                return -1; // Return -1 to indicate empty stack
            }
        }
        int value = stacks[current_stack].back();
        stacks[current_stack].pop_back();
        return value;
    }

    int popAt(int index) {
        if (index < 0 || index >= stacks.size()) {
            return -1; // Return -1 to indicate invalid index
        }

        if (stacks[index].empty()) {
            return -1; // Return -1 to indicate empty stack
        }

        int value = stacks[index].back();
        stacks[index].pop_back();
        return value;
    }
};

// Example usage:
int main() {
    SetOfStacks set_of_stacks(3);
    set_of_stacks.push(1);
    set_of_stacks.push(2);
    set_of_stacks.push(3);
    set_of_stacks.push(4);

    cout << set_of_stacks.pop() << endl;   // Output: 4
    cout << set_of_stacks.pop() << endl;   // Output: 3
    cout << set_of_stacks.popAt(0) << endl; // Output: 2 
    cout << set_of_stacks.pop() << endl;   // Output: 1

    return 0;
}
