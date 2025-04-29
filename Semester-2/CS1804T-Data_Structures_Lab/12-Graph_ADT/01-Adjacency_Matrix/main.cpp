#include <iostream>
#include <vector>
using namespace std;

// --- Graph Class ---
class Graph {
private:
  int numVertices;
  vector<vector<int>> adj;

  bool valid(int u, int v); // Private helper

public:
  Graph(int V); // Constructor
  void insertEdge(int u, int v);
  void deleteEdge(int u, int v);
  void searchEdge(int u, int v);
  void display();
};

// Main Function
int main() {
  int V;
  cout << "Enter number of vertices: ";
  cin >> V;

  Graph g(V);
  int u, v;
  int choice;

  while (true) {
    cout << "\n--- Graph Menu ---\n";
    cout << "1. Insert Edge\n";
    cout << "2. Delete Edge\n";
    cout << "3. Search Edge\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter edge (u v): ";
      cin >> u >> v;
      g.insertEdge(u, v);
      break;
    case 2:
      cout << "Enter edge (u v): ";
      cin >> u >> v;
      g.deleteEdge(u, v);
      break;
    case 3:
      cout << "Enter edge (u v): ";
      cin >> u >> v;
      g.searchEdge(u, v);
      break;
    case 4:
      g.display();
      break;
    case 5:
      cout << "Exiting...\n";
      return 0;
    default:
      cout << "Invalid choice. Try again!\n";
    }
  }
}

// --- Function Definitions ---
Graph::Graph(int V) {
  numVertices = V;
  adj.resize(V, vector<int>(V, 0));
}

bool Graph::valid(int u, int v) {
  return u >= 0 && v >= 0 && u < numVertices && v < numVertices;
}

void Graph::insertEdge(int u, int v) {
  if (valid(u, v)) {
    adj[u][v] = 1;
    cout << "Edge inserted from " << u << " to " << v << endl;
  } else {
    cout << "Invalid vertices!\n";
  }
}

void Graph::deleteEdge(int u, int v) {
  if (valid(u, v)) {
    adj[u][v] = 0;
    cout << "Edge deleted from " << u << " to " << v << endl;
  } else {
    cout << "Invalid vertices!\n";
  }
}

void Graph::searchEdge(int u, int v) {
  if (valid(u, v)) {
    if (adj[u][v] == 1)
      cout << "Edge exists from " << u << " to " << v << endl;
    else
      cout << "Edge does not exist.\n";
  } else {
    cout << "Invalid vertices!\n";
  }
}

void Graph::display() {
  cout << "\nAdjacency Matrix:\n";
  for (int i = 0; i < numVertices; ++i) {
    for (int j = 0; j < numVertices; ++j) {
      cout << adj[i][j] << " ";
    }
    cout << endl;
  }
}
