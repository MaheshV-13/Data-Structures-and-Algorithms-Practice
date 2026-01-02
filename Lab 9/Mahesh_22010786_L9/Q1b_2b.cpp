#include <iostream>
#include <vector>
using namespace std;

const int V = 5; // A, B, C, D, E → 0 to 4

int adjMatrix[V][V];
vector<pair<int, int>> adjList[V];
bool visited[V];

// Helper for character → index
int charToIndex(char c) {
    return c - 'A';
}

char indexToChar(int index) {
    return 'A' + index;
}

// Add edge to both matrix and list
void addEdge(char uChar, char vChar, int weight) {
    int u = charToIndex(uChar);
    int v = charToIndex(vChar);
    adjMatrix[u][v] = weight;
    adjList[u].push_back({v, weight});
}

// Print adjacency matrix
void printAdjMatrix() {
    cout << "=== Adjacency Matrix ===\n";
    cout << "    ";
    for (int j = 0; j < V; ++j)
        cout << indexToChar(j) << "\t";
    cout << "\n";

    for (int i = 0; i < V; ++i) {
        cout << indexToChar(i) << " | ";
        for (int j = 0; j < V; ++j) {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << "\n";
    }
}

// Print adjacency list
void printAdjList() {
    cout << "\n=== Adjacency List ===\n";
    for (int i = 0; i < V; ++i) {
        cout << indexToChar(i) << " -> ";
        for (auto it : adjList[i]) {
            int neighbor = it.first;
            int weight = it.second;
            cout << "(" << indexToChar(neighbor) << ", " << weight << ") ";
        }
        cout << "\n";
    }
}

// DFS path checker
bool dfs_path_exists(int current, int target) {
    if (current == target) return true;
    visited[current] = true;

    for (auto edge : adjList[current]) {
        int neighbor = edge.first;
        if (!visited[neighbor]) {
            if (dfs_path_exists(neighbor, target)) return true;
        }
    }
    return false;
}

int main() {
    // Initialize matrix
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            adjMatrix[i][j] = 0;

    // Add edges
    addEdge('A', 'C', 12);
    addEdge('A', 'D', 60);
    addEdge('B', 'A', 10);
    addEdge('C', 'B', 20);
    addEdge('C', 'D', 32);
    addEdge('E', 'A', 7);

    // Print graph representations
    printAdjMatrix();
    printAdjList();

    // Check paths
    vector<pair<char, char>> pathsToCheck = {
        {'A', 'C'},
        {'B', 'D'},
        {'B', 'E'}
    };

    for (auto p : pathsToCheck) {
        char from = p.first, to = p.second;
        int u = charToIndex(from);
        int v = charToIndex(to);

        fill(visited, visited + V, false);
        cout << "\nChecking path from " << from << " to " << to << "...\n";
        if (dfs_path_exists(u, v))
            cout << "Path exists from " << from << " to " << to << "\n";
        else
            cout << "No path from " << from << " to " << to << "\n";
    }

    return 0;
}
