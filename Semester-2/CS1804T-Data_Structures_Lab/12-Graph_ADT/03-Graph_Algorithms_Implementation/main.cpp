#include<iostream>
#include "heap.h"
#include "adjlist.h"
#include<map>
#include<climits>
#include<vector>
using namespace std;

// Disjoint Set (Union-Find) class
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }

    void unite(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class graph {
    heap h;
    Node l = Node(0);
    Node l2 = Node(0);
    int vertices;

public:
    graph() {
        int n;
        cout << "Enter the number of vertices in the graph: ";
        cin >> n;
        vertices = n;
        l = Node(n);
        l2 = Node(n);
    }

    void insert(int u, int v, int weight) {
        l.insert(u, v, weight);
    }

    void kruskals() {
        heap priorityQueue;
        int mstWeight = 0;
        DisjointSet ds(vertices);

        // Add all edges to heap
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                int weight = l.search(i, j);
                if (weight > 0) {
                    priorityQueue.insert(i, j, weight);
                }
            }
        }
        cout << "Edges in MST (Kruskal's algorithm):\n";

        while (!priorityQueue.isEmpty()) {
            auto edge = priorityQueue.getMin();
            int u = edge.first;
            int v = edge.second;
            int weight = edge.third;
            priorityQueue.delete_root();

            if (ds.find(u) == ds.find(v)) continue;
            ds.unite(u, v);

            l2.insert(u, v, weight);
            cout << u << " -- " << v << " : " << weight << endl;
            mstWeight += weight;
        }
        cout << "Total MST weight: " << mstWeight << endl;
    }

    void prims(int start) {
        map<int, bool> visited;
        heap priorityQueue;

        visited[start] = true;

        for (int i = 0; i < vertices; i++) {
            if (i != start) {
                int weight = l.search(start, i);
                if (weight > 0) {
                    priorityQueue.insert(start, i, weight);
                }
            }
        }

        int mstWeight = 0;
        cout << "Edges in MST (Prim's algorithm):\n";

        while (!priorityQueue.isEmpty() && visited.size() < vertices) {
            auto edge = priorityQueue.getMin();
            int u = edge.first;
            int v = edge.second;
            int weight = edge.third;
            priorityQueue.delete_root();

            if (visited[v]) continue;

            l2.insert(u, v, weight);
            mstWeight += weight;
            cout << u << " -- " << v << " : " << weight << endl;

            visited[v] = true;

            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    int edgeWeight = l.search(v, i);
                    if (edgeWeight > 0) {
                        priorityQueue.insert(v, i, edgeWeight);
                    }
                }
            }
        }

        cout << "Total MST weight: " << mstWeight << endl;
    }

    void dijkstra(int start) {
        map<int, bool> visited;
        vector<int> distance(vertices, INT_MAX);
        distance[start] = 0;
        while (!visited[start]) {
            for (int i = 0; i < vertices; i++) {
                if (i != start) {
                    int weight = l.search(start, i);
                    if (weight > 0) {
                        if (distance[start] + weight < distance[i]) {
                            distance[i] = distance[start] + weight;
                        }
                    }
                }
            }
            visited[start] = true;
            int minim = INT_MAX;
            for (int i = 0; i < vertices; i++) {
                if (!visited[i] && distance[i] < minim) {
                    minim = distance[i];
                    start = i;
                }
            }
        }
        cout << "Shortest distances from start vertex:\n";
        for (int i = 0; i < vertices; i++) {
            cout << "Distance to vertex " << i << ": " << distance[i] << endl;
        }
    }

    void display() {
        cout << "Original Graph:\n";
        l.display();
        cout << "\nMST/Result Graph:\n";
        l2.display();
    }
};

int main() {
    graph g;
    int choice, u, v, w, start;

    while (true) {
        cout << "\n----- Graph Algorithm Menu -----\n";
        cout << "1. Insert Edge\n";
        cout << "2. Prim's Algorithm\n";
        cout << "3. Kruskal's Algorithm\n";
        cout << "4. Dijkstra's Algorithm\n";
        cout << "5. Display Graph\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> w;
                g.insert(u, v, w);
                break;
            case 2:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.prims(start);
                break;
            case 3:
                g.kruskals();
                break;
            case 4:
                cout << "Enter starting vertex: ";
                cin >> start;
                g.dijkstra(start);
                break;
            case 5:
                g.display();
                break;
            case 6:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
