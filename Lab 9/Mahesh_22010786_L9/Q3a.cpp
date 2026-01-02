#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Union-Find (Disjoint Set Union - DSU)
class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);  // Path compression
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv)
            return false;
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

int main() {
    const int V = 9;  // Number of vertices (0 to 8)
    vector<Edge> edges = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}, {8, 3, 4}
    };

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    UnionFind uf(V);
    vector<Edge> mst;
    int totalWeight = 0;

    for (const auto& edge : edges) {
        if (uf.unite(edge.u, edge.v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            if (mst.size() == V - 1)
                break;
        }
    }

    // Print MST
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }

    cout << "Total Weight of MST: " << totalWeight << endl;

    return 0;
}
