#include "Comb.hpp"
#include "common.hpp"
#include "PrimeTable.hpp"
#include "SparseTable.hpp"
#include "Mod.hpp"


class Solution {
public:
    int maximumPoints(const vector<vector<int> > &edges, const vector<int> &coins, int k) {
        int n = coins.size();
        vector<vector<int> > adj(n, vector<int>());
        for (auto &e: edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        const int N = 14;
        vector<vector<int> > dp(n, vector<int>(14, 0));
        vector<bool> visited(n, false);
        function<void(int, int)> dfs = [&](int i, int prev) {
            if (visited[i]) return;
            visited[i] = true;

            for (int v: adj[i]) {
                if (v == prev) continue;
                dfs(v, i);
            }

            for (int j = 0; j < N; j++) {
                int v = coins[i] >> j;
                int rst = v - k;
                for (int v: adj[i]) {
                    if (v == prev) continue;
                    rst += dp[v][j];
                }
                dp[i][j] = rst;

                rst = v / 2;
                if (j != N - 1) {
                    for (int v: adj[i]) {
                        if (v == prev) continue;
                        rst += dp[v][j + 1];
                    }
                }
                dp[i][j] = max(dp[i][j], rst);
            }
        };

        dfs(0, -1);
        return dp[0][0];
    }
};

int main() {
    Mod<long long> md(11);
    auto v = md.mod_inverse(3);
    auto v2 = md.mod_inverse_egcd(3);
    _print(v, v2);

    md.mod = 13;
    auto v3 = md.get_inverses(10);
    _print(v3);

    Mod<long long> md2(1e9+7);
    _print(md2.mod_inverse(3));
    _print(md2.mod_inverse(13));

    Mod<long long> md3;
    long long x, y;
    md3.extended_gcd(3, 5, x, y);
    _print(x, y);

}
