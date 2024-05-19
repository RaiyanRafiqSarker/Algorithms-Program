#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

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

    void bellmanFord(int source, int destination) {
        vector<int> distance(V, INT_MAX);
        distance[source] = 0;

        // Relax all edges |V| - 1 times
        for (int i = 1; i <= V - 1; ++i) {
            for (auto edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int w = edge.weight;
                if (distance[u] != INT_MAX && distance[u] + w < distance[v])
                    distance[v] = distance[u] + w;
            }
        }

        // Check for negative-weight cycles
        for (auto edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;
            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                cout << "Graph contains negative weight cycle\n";
                return;
            }
        }

        // Print shortest distances
        cout << "Shortest distance from " << source << " to " << destination << ": " << distance[destination] << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V, E);

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    int source, destination;
    cout << "Enter source and destination nodes: ";
    cin >> source >> destination;

    graph.bellmanFord(source, destination);

    return 0;
}
