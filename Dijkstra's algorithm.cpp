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
    }

    vector<int> dijkstra(int source) {
        vector<int> distance(V, INT_MAX);
        distance[source] = 0;

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, source));

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;

                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    pq.push(make_pair(distance[v], v));
                }
            }
        }

        return distance;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        graph.addEdge(source, destination, weight);
    }

    int source, destination;
    cout << "Enter source and destination nodes: ";
    cin >> source >> destination;

    vector<int> distance = graph.dijkstra(source);

    cout << "Shortest distance from " << source << " to " << destination << ": " << distance[destination] << endl;

    return 0;
}

