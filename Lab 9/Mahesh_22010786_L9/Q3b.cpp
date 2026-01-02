#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Edge {
    char u, v;
    int weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

class UnionFind {
    vector<int> parent, rank;

public:
    UnionFind(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
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
    vector<Edge> edges = {
        {'A', 'B', 5}, {'A', 'C', 2}, {'B', 'C', 6}, {'B', 'D', 2}, {'B', 'F', 8},
        {'C', 'F', 4}, {'C', 'E', 1}, {'D', 'F', -9}, {'D', 'G', 7},
        {'E', 'F', -6}, {'E', 'G', 2}, {'F', 'G', 1}
    };

    unordered_map<char, int> charToIndex;
    unordered_map<int, char> indexToChar;
    int idx = 0;
    for (const auto& e : edges) {
        if (charToIndex.count(e.u) == 0) {
            charToIndex[e.u] = idx;
            indexToChar[idx] = e.u;
            idx++;
        }
        if (charToIndex.count(e.v) == 0) {
            charToIndex[e.v] = idx;
            indexToChar[idx] = e.v;
            idx++;
        }
    }

    int n = idx;
    sort(edges.begin(), edges.end());

    UnionFind uf(n);
    vector<Edge> mst;
    int totalWeight = 0;

    for (const auto& edge : edges) {
        int u = charToIndex[edge.u];
        int v = charToIndex[edge.v];

        if (uf.unite(u, v)) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            if (mst.size() == n - 1)
                break;
        }
    }

    cout << "Minimum Spanning Tree (char nodes):\n";
    for (const auto& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }

    cout << "Total Weight: " << totalWeight << endl;
    return 0;
}
