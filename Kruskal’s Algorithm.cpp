#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int source, destination, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
    int V, E;
    vector<Edge> edges;

public:
    Graph(int V, int E) {
        this->V = V;
        this->E = E;
    }

    void addEdge(int source, int destination, int weight) {
        edges.push_back({source, destination, weight});
    }

    int find(vector<Subset>& subsets, int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }

    void unionSets(vector<Subset>& subsets, int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    void kruskalMST() {
        vector<Edge> result;

        // Sort all edges by weight
        sort(edges.begin(), edges.end(), compareEdges);

        vector<Subset> subsets(V);
        for (int v = 0; v < V; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }

        int i = 0, e = 0;
        while (e < V - 1 && i < E) {
            Edge next_edge = edges[i++];

            int x = find(subsets, next_edge.source);
            int y = find(subsets, next_edge.destination);

            if (x != y) {
                result.push_back(next_edge);
                unionSets(subsets, x, y);
                e++;
            }
        }

        // Print MST
        cout << "Edges in MST:\n";
        for (auto edge : result) {
            cout << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V, E);

    cout << "Enter edges and weights (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    graph.kruskalMST();

    return 0;
}
