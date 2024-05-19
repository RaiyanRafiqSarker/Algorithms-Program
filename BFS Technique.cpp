#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

void BFS(const vector<vector<char>>& graph, char start, char target) {
    unordered_map<char, bool> visited;
    unordered_map<char, char> parent;
    queue<char> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        if (current == target) {
            cout << "Path from " << start << " to " << target << ": ";
            while (current != start) {
                cout << current << " <- ";
                current = parent[current];
            }
            cout << start << endl;
            return;
        }

        for (char neighbor : graph[current - 'A']) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = current;
            }
        }
    }

    cout << "Path from " << start << " to " << target << " not found!\n";
}

int main() {

    vector<vector<char>> graph = {
        {'B', 'C'},     // A
        {'A', 'D', 'E'},// B
        {'A'},          // C
        {'B', 'F', 'G'},// D
        {'B'},          // E
        {'D', 'H', 'I'},// F
        {'D'},          // G
        {'F'},          // H
        {'F', 'J'},     // I
        {'I'}           // J
    };

    BFS(graph, 'A', 'J');

    return 0;
}
