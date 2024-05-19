#include <iostream>

using namespace std;

// Number of vertices in the graph
#define NUM_VERTICES 6

// Define the vertices using letters for easier understanding
enum Vertex {
    J = 0, // J is mapped to index 0
    K,     // K is mapped to index 1
    L,     // L is mapped to index 2
    M,     // M is mapped to index 3
    N,     // N is mapped to index 4
    F      // F is mapped to index 5
};

// Adjacency matrix of the graph
int adjMatrix[NUM_VERTICES][NUM_VERTICES] = {
    // J  K  L  M  N  F
    {0, 1, 0, 0, 0, 0}, // J
    {1, 0, 1, 0, 0, 0}, // K
    {0, 1, 0, 1, 1, 0}, // L
    {0, 0, 1, 0, 0, 1}, // M
    {0, 0, 1, 0, 0, 0}, // N
    {0, 0, 0, 1, 0, 0}  // F
};

// Array to keep track of visited vertices
bool visited[NUM_VERTICES];

// Function to perform DFS and find a path from start to end
void DFS(int start, int end, int path[], int &pathIndex) {
    // Mark the current vertex as visited
    visited[start] = true;

    // Add the current vertex to the path
    path[pathIndex] = start;
    pathIndex++;

    // Check if the end vertex is reached
    if (start == end) {
        // Print the path
        cout << "Path from J to F: ";
        for (int i = 0; i < pathIndex; i++) {
            switch (path[i]) {
                case J:
                    cout << "J ";
                    break;
                case K:
                    cout << "K ";
                    break;
                case L:
                    cout << "L ";
                    break;
                case M:
                    cout << "M ";
                    break;
                case N:
                    cout << "N ";
                    break;
                case F:
                    cout << "F ";
                    break;
            }
        }
        cout << endl;
        return; // Path found, return
    }

    // Explore adjacent vertices
    for (int i = 0; i < NUM_VERTICES; i++) {
        if (adjMatrix[start][i] == 1 && !visited[i]) {
            DFS(i, end, path, pathIndex);
            // If the end vertex has been found, backtrack the current path
            if (pathIndex > 0 && path[pathIndex - 1] == end) {
                return;
            }
        }
    }

    // Backtrack: remove the current vertex from the path and mark as unvisited
    pathIndex--;
    visited[start] = false;
}

// Main function
int main() {
    // Display the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    cout << "  J K L M N F" << endl;
    for (int i = 0; i < NUM_VERTICES; i++) {
        switch (i) {
            case J:
                cout << "J ";
                break;
            case K:
                cout << "K ";
                break;
            case L:
                cout << "L ";
                break;
            case M:
                cout << "M ";
                break;
            case N:
                cout << "N ";
                break;
            case F:
                cout << "F ";
                break;
        }
        for (int j = 0; j < NUM_VERTICES; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Array to keep track of the path
    int path[NUM_VERTICES];
    int pathIndex = 0;

    // Initialize the visited array to false
    fill_n(visited, NUM_VERTICES, false);

    // Find a path from vertex J to vertex F using DFS
    DFS(J, F, path, pathIndex);

    return 0;
}
