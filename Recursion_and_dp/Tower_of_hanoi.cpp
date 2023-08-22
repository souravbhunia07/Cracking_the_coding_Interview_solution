#include <iostream>
#include <stack>

void towerOfHanoi(int n, std::stack<int>& source, std::stack<int>& auxiliary, std::stack<int>& destination, int towerNum[]) {
    if (n == 1) {
        int disk = source.top();
        source.pop();
        destination.push(disk);
        std::cout << "Move disk " << disk << " from Tower " << towerNum[0] << " to Tower " << towerNum[2] << std::endl;
        return;
    }

    towerOfHanoi(n - 1, source, destination, auxiliary, towerNum);

    int disk = source.top();
    source.pop();
    destination.push(disk);
    std::cout << "Move disk " << disk << " from Tower " << towerNum[0] << " to Tower " << towerNum[2] << std::endl;

    towerOfHanoi(n - 1, auxiliary, source, destination, towerNum);
}

int toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        cout << "Moves from " << a << " to C " << c <<endl;
        toh(n - 1, b, a, c); 
    }
}

int main() {
    int n; // Number of disks
    std::cout << "Enter the number of disks: ";
    std::cin >> n;

    std::stack<int> towerA, towerB, towerC;

    // Initialize tower A with disks
    for (int i = n; i > 0; --i) {
        towerA.push(i);
    }

    int towerNum[] = {1, 2, 3}; // Tower numbers

    towerOfHanoi(n, towerA, towerB, towerC, towerNum);

    toh(3, 1, 2, 3);

    return 0;
}
