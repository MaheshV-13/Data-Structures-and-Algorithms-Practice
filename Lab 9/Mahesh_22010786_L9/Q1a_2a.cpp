#include <iostream>
#include <vector>
using namespace std;

const int V = 5;

int adjMatrix[V][V];

vector<pair<int, int>> adjList[V];

bool visited[V];

void addEdge(int u, int v, int weight) {
    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight;

    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});
}

void printAdjMatrix() {
    cout << "Adjacency Matrix\n";
    cout << "    ";
    for (int j = 0; j < V; ++j) cout << j << "\t";
    cout << "\n";

    for (int i = 0; i < V; ++i) {
        cout << i << " | ";
        for (int j = 0; j < V; ++j) {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printAdjList() {
    cout << "Adjacency List\n";
    for (int i = 0; i < V; ++i) {
        cout << i << " -> ";
        for (auto it : adjList[i]) {
            int neighbor = it.first;
            int weight = it.second;
            cout << "(" << neighbor << ", " << weight << ") ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool dfs_path_exists(int current, int target) {
    if (current == target) return true;
    visited[current] = true;

    for (auto edge : adjList[current]) {
        int neighbor = edge.first;
        if (!visited[neighbor]) {
            if (dfs_path_exists(neighbor, target)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = false;
    }

    addEdge(0, 1, 10);
    addEdge(0, 4, 20);
    addEdge(1, 2, 30);
    addEdge(1, 3, 40);
    addEdge(1, 4, 50);
    addEdge(2, 3, 60);
    addEdge(3, 4, 70);

    printAdjMatrix();
    printAdjList();

    cout << "Checking...\n";
    fill(visited, visited + V, false);

    if (dfs_path_exists(1, 3))
        cout << "Path exists from 1 to 3\n";
    else
        cout << "No path exists from 1 to 3\n";

    return 0;
}
