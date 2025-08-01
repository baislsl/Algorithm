//
// Created by baislsl on 2025/7/13.
//

#include "common.hpp"

class Solution {
public:
    int maxLen(int n, const vector<vector<int> > &edges, string label) {
        vector<vector<vector<int> > > dp(1 << n, vector<vector<int> >(n, vector<int>(n, INT_MIN)));
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                dp[1 << i][i][i] = 1;
            }
        }
        int ans = 1;
        vector<vector<int> > adj(n, vector<int>());
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            if (label[u] == label[v]) {
                dp[(1 << u) | (1 << v)][u][v] = 2;
                dp[(1 << u) | (1 << v)][v][u] = 2;
                ans = 2;
            }
        }
        for (int mask = 0; mask < (1 << n); mask++) {
            for (int i = 0; i < n; i++) {
                if (!(mask & (1 << i))) continue;
                for (int j = 0; j < n; j++) {
                    if (!(mask & (1 << j)) || label[i] != label[j]) continue;
                    for (auto ni: adj[i]) {
                        if (mask & (1 << ni)) continue;
                        for (auto nj: adj[j]) {
                            if ((mask & (1 << nj)) || ni == nj || label[ni] != label[nj]) continue;
                            int nmask = mask + (1 << ni) + (1 << nj);
                            dp[nmask][ni][nj] = max(dp[nmask][ni][nj], dp[mask][i][j] + 2);
                            ans = max(ans, dp[nmask][ni][nj]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution s;
    _print(s.maxLen(3, {{0, 1}, {1, 2}}, "aba"));
}
