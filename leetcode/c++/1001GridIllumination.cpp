#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>> lamps, vector<vector<int>> queries) {
        int n = N;
        vector<bool> closed(lamps.size(), false);
        vector<int> ans;

        std::map<int, vector<int>> xmap, ymap, lmap, rmap;
        map<int,map<int,int>> ss;
        for(int i = 0; i < lamps.size(); i ++) {
            int x= lamps[i][0], y = lamps[i][1];
            xmap[x].push_back(i);
            ymap[y].push_back(i);
            lmap[x + y].push_back(i);
            rmap[x-y+n].push_back(i);
            ss[x][y] = i + 1;
        }
        for(int i = 0; i < queries.size(); i ++) {
            int x = queries[i][0], y =queries[i][1];
            int result = 0;
            int contin = true;
            for(auto &vec : array<vector<int>, 4> {xmap[x], ymap[y], lmap[x+y], rmap[x-y+n]}) {
                for(auto ind : vec) {
                    //cout << ind << endl;
                    if(!closed[ind]) {
                        result = 1;
                    }
                }
            }
            ans.push_back(result);


            // close
            for(int u = -1; u <=1; u ++) {
                for(int v = -1; v <= 1; v ++) {
                    int ind = ss[x +u][y+v];
                    if (ind) {
                        closed[ind -1] = true;
                    }
                }
            }
        }

        return ans;
    }

};


int main() {
    Solution s;
    auto result = s.gridIllumination(5, {{0, 0}, {4, 4}}, {{1,1}, {1, 0}});
    for(auto i :  result ){
        cout << i << " " ;
    }

}


