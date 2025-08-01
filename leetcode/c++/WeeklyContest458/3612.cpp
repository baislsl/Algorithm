//
// Created by baislsl on 2025/7/13.
//

#include "common.hpp"

class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return false;

        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX] += 1;
        }
        return true;
    }
};

class Solution {
public:
    int minCost(int n, vector<vector<int> > &edges, int k) {
        DSU dsu(n);
        sort(edges.begin(), edges.end(), [&](const vector<int> &x, const vector<int> &y) {
            return x[2] < y[2];
        });
        int gp = n;
        int ans = 0;
        for (auto &e: edges) {
            if (dsu.unite(e[0], e[1])) {
                gp--;
            }
            if (gp == k) {
                ans = e[2];
                break;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << "123" << endl;
}
