#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Function to check if there is a route between two nodes using BFS
bool isRouteBetweenNodes(const vector<vector<int>>& graph, int startNode, int endNode) {
    if (startNode == endNode) {
        return true; // A node is always reachable from itself
    }

    queue<int> q;
    unordered_set<int> visited;

    q.push(startNode);
    visited.insert(startNode);

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for (int neighbor : graph[currentNode]) {
            if (neighbor == endNode) {
                return true; // Found a route to the endNode
            }

            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }

    return false; // No route found
}

int main() {
    // Example usage
    int numNodes = 6;
    vector<vector<int>> graph(numNodes);

    // Adding edges to the graph
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(1);

    int startNode = 0;
    int endNode = 4;

    if (isRouteBetweenNodes(graph, startNode, endNode)) {
        cout << "There is a route between nodes " << startNode << " and " << endNode << ".\n";
    } else {
        cout << "There is no route between nodes " << startNode << " and " << endNode << ".\n";
    }

    return 0;
}
