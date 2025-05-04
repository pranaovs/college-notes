#include <iostream>
#include<vector>
using namespace std;

class Node {
    struct node {
        int data;
        int weight;
        node* next;
    };
    vector<node*> adjList; // Adjacency list
    int n; // Number of vertices

public:
    Node(int vertices) {
        n = vertices;
        adjList.resize(n, nullptr); // Initialize adjacency list with null pointers
    }

    void insert(int u, int v,int weight) {
        if (u >= n || v >= n) {
            cout << "Invalid vertex\n";
            return;
        }
        node* newNode = new node{v, weight,adjList[u]};
        adjList[u] = newNode; // Insert at the head of the list for vertex u

        newNode = new node{u,weight, adjList[v]};
        adjList[v] = newNode; // Insert at the head of the list for vertex v
    }

    void deleteEdge(int u, int v) {
        if (u >= n || v >= n) {
            cout << "Invalid vertex\n";
            return;
        }
        // Delete edge from u to v
        node* temp = adjList[u];
        node* prev = nullptr;
        while (temp != nullptr && temp->data != v) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) { // Edge found
            if (prev == nullptr) { // Edge is at the head
                adjList[u] = temp->next;
            } else {
                prev->next = temp->next; // Bypass the node
            }
            delete temp; // Free memory
        }

        // Delete edge from v to u (since it's undirected)
        temp = adjList[v];
        prev = nullptr;
        while (temp != nullptr && temp->data != u) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) { // Edge found
            if (prev == nullptr) { // Edge is at the head
                adjList[v] = temp->next;
            } else {
                prev->next = temp->next; // Bypass the node
            }
            delete temp; // Free memory
        }
    }
    int search(int u, int v) {
        if (u >= n || v >= n) {
            cout << "Invalid vertex\n";
            return 0;
        }
        node* temp = adjList[u];
        while (temp != nullptr) {
            if (temp->data == v) {
                return temp->weight;
            }
            temp = temp->next;
        }
        return 0;
    }
    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            node* temp = adjList[i];
            while (temp != nullptr) {
                cout << temp->data << " -("<<temp->weight<<")> ";
                temp = temp->next;
            }
            cout << "nullptr\n";
        }
    }
};