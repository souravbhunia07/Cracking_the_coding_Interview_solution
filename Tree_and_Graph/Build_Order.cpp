#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<char> findBuildOrder(const vector<char>& projects, const vector<pair<char, char>>& dependencies) {
    vector<char> buildOrder;
    unordered_map<char, int> indegree;
    unordered_map<char, vector<char>> adj;

    // Initialize indegree and adjacency list
    for (char project : projects) {
        indegree[project] = 0;
        adj[project] = vector<char>();
    }

    // Populate indegree and adjacency list based on dependencies
    for (const auto& dependency : dependencies) {
        char from = dependency.first;
        char to = dependency.second;
        adj[from].push_back(to);
        indegree[to]++;
    }

    queue<char> q;

    // Initialize the queue with nodes having zero indegree
    for (const auto& entry : indegree) {
        if (entry.second == 0) {
            q.push(entry.first);
        }
    }

    while (!q.empty()) {
        char curr = q.front();
        q.pop();
        buildOrder.push_back(curr);

        for (char neighbor : adj[curr]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if (buildOrder.size() == projects.size()) {
        return buildOrder;
    }

    return {}; // No valid build order
}

int main() {
    vector<char> projects = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<pair<char, char>> dependencies = {
        {'a', 'd'},
        {'f', 'b'},
        {'b', 'd'},
        {'f', 'a'},
        {'d', 'c'}
    };

    vector<char> buildOrder = findBuildOrder(projects, dependencies);

    if (!buildOrder.empty()) {
        cout << "Valid Build Order: ";
        for (char project : buildOrder) {
            cout << project << " ";
        }
        cout << endl;
    } else {
        cout << "No valid build order exists." << endl;
    }

    return 0;
}
