//
// Created by baislsl on 2025/7/19.
//

#include "common.hpp"

using namespace std;

class Solution {
public:
    using ll = long long;
    int findMaxPathScore(const vector<vector<int> > &edges, const vector<bool> &online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int> > > gp(n, vector<pair<int, int> >());
        for (auto e: edges) {
            int u = e[0], v = e[1], cost = e[2];
            gp[u].push_back(make_pair(v, cost));
        }

        auto valid = [&](int tg) {
            vector<bool> fg(n, false);
            set<pair<int, ll> > st;
            st.insert(make_pair(0, 0));
            while (!st.empty()) {
                auto it = st.begin();
                int v = it->second;
                ll cost = it->first;
                st.erase(it);
                if (v == n - 1) return true;
                if (fg[v]) continue;
                fg[v] = true;
                for (auto [nx, ct]: gp[v]) {
                    auto _ = nx;
                    if (fg[nx] || ct < tg || !online[nx] || cost + ct > k) continue;
                    st.insert(make_pair(cost + ct, nx));
                }

            }
            return false;
        };

        int lf = 0, ri = 1e9;
        int ans = -1;
        auto cc = valid(49);
        if (!valid(0)) return -1;
        while (lf <= ri) {
            int mid = lf + (ri - lf) / 2;
            if (valid(mid)) {
                lf = mid + 1;
                ans = mid;
            } else {
                ri = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    _print(s.findMaxPathScore({{5,6,53},{0,3,68},{3,4,67},{0,6,24},{1,3,49},{4,6,28},{0,2,74},{1,5,98},{2,4,86},{1,6,19},{3,6,21},{2,5,8}}, {true,true,true,true,true,true,true}, 402));
    _print(s.findMaxPathScore({{0,1,5},{1,3,10},{0,2,3},{2,3,4}}, {true, true, true, true}, 10));
}
