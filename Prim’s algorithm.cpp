#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

class Graph {
    int V;
    vector<vector<pii>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(make_pair(v, weight));
        adj[v].push_back(make_pair(u, weight)); // For undirected graph
    }

    vector<int> primMST() {
        vector<int> parent(V, -1);
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, 0));
        key[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;

                if (!inMST[v] && key[v] > weight) {
                    key[v] = weight;
                    pq.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }

        return parent;
    }

    void printMST(const vector<int>& parent) {
        cout << "Edges in MST:\n";
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << "\n";
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter edges and weights (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    vector<int> parent = graph.primMST();

    graph.printMST(parent);

    return 0;
}
