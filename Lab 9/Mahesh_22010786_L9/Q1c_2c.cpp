#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Graph {
    vector<string> vertices;
    vector<vector<int>> adjMatrix;

public:
    void addVertex(const string& name) {
        for (int i = 0; i < vertices.size(); ++i) {
            if (vertices[i] == name) return; // Avoid duplicates
        }
        vertices.push_back(name);
        for (int i = 0; i < adjMatrix.size(); ++i) {
            adjMatrix[i].push_back(0); // add new column
        }
        adjMatrix.push_back(vector<int>(vertices.size(), 0)); // add new row
    }

    void addEdge(const string& from, const string& to, int weight) {
        addVertex(from);
        addVertex(to);
        int i = getIndex(from);
        int j = getIndex(to);
        if (i != -1 && j != -1) {
            adjMatrix[i][j] = weight; // directed edge
        }
    }

    int getIndex(const string& name) {
        for (int i = 0; i < vertices.size(); ++i) {
            if (vertices[i] == name) return i;
        }
        return -1;
    }

    void displayAdjMatrix() {
        cout << "\nAdjacency Matrix (Directed):\n     ";
        for (int i = 0; i < vertices.size(); ++i)
            cout << vertices[i] << "\t";
        cout << endl;

        for (int i = 0; i < vertices.size(); ++i) {
            cout << vertices[i] << " ";
            for (int j = 0; j < vertices.size(); ++j) {
                cout << "\t" << adjMatrix[i][j];
            }
            cout << endl;
        }
    }

    void displayAdjList() {
        cout << "\nAdjacency List (Directed):\n";
        for (int i = 0; i < vertices.size(); ++i) {
            cout << vertices[i] << " -> ";
            for (int j = 0; j < vertices.size(); ++j) {
                if (adjMatrix[i][j] != 0) {
                    cout << vertices[j] << "(" << adjMatrix[i][j] << ") ";
                }
            }
            cout << endl;
        }
    }

    void checkDirectPath(const string& from, const string& to) {
        int i = getIndex(from);
        int j = getIndex(to);
        if (i != -1 && j != -1 && adjMatrix[i][j] != 0)
            cout << "Direct path exists: " << from << " → " << to << endl;
        else
            cout << "Direct path does NOT exist: " << from << " → " << to << endl;
    }
};

int main() {
    Graph g;

    g.addEdge("Austin", "Dallas", 200);
    g.addEdge("Austin", "Houston", 160);
    g.addEdge("Dallas", "Austin", 1000);
    g.addEdge("Dallas", "Chicago", 200);
    g.addEdge("Dallas", "Denver", 780);
    g.addEdge("Houston", "Atlanta", 800);
    g.addEdge("Atlanta", "Washington", 600);
    g.addEdge("Atlanta", "Houston", 800);
    g.addEdge("Washington", "Dallas", 1300);
    g.addEdge("Washington", "Atlanta", 600);
    g.addEdge("Chicago", "Denver", 1000);
    g.addEdge("Denver", "Atlanta", 1400);
    g.addEdge("Denver", "Chicago", 1000);

    g.displayAdjList();
    g.displayAdjMatrix();

    cout << "\nPath Checks (Direct Only):\n";
    g.checkDirectPath("Dallas", "Washington");  // No
    g.checkDirectPath("Houston", "Austin");     // No

    return 0;
}
