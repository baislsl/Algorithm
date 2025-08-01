//
// Created by baislsl on 2025/7/19.
//

#include "common.hpp"

using namespace std;

class Solution {
public:
    int countIslands(const vector<vector<int> > &grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool> > fg(n, vector<bool>(m, false));
        vector<int> dir{0, 1, 0, -1, 0};
        function<long(int, int)> trav = [&](int x, int y) -> long {
            if (fg[x][y]) return 0;
            long rst = grid[x][y];
            fg[x][y] = true;
            if (rst == 0) return 0;
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d], ny = y + dir[d + 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (grid[nx][ny] == 0 || fg[nx][ny]) continue;
                rst += trav(nx, ny);
            }
            return rst;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                long rst = trav(i, j);
                if (rst > 0 && rst % k == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    _print(s.countIslands({{0,2,1,0,0},{0,5,0,0,5},{0,0,1,0,0},{0,1,4,7,0},{0,2,0,0,8}}, 5));
}
