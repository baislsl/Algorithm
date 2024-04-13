//
// Created by baishengli on 2020-01-11.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>


using namespace std;

class Solution {
public:
    void dfs(int cur, vector<vector<int>>& es, vector<vector<int>>& vi, int thre, vector<int>&dis, int curDis,
             int &ans, vector<bool>& found, vector<vector<int>>& next) {
        if(curDis > thre) {
            return;
        } else {
            if(!found[cur]) {
                ans += 1;
                found[cur] = true;
                dis[cur] = min(dis[cur], curDis);
            } else if(dis[cur] <= curDis){
                return;
            }
        }

        for(int i = 0; i < next[cur].size(); i ++) {
            dfs(next[cur][i], es, vi, thre, dis, curDis + es[vi[cur][i]][2], ans, found, next);
        }
        cout << cur << endl;

    }
    int findTheCity(int n, vector<vector<int>>& es, int thre) {
        vector<vector<int>> vi;
        vector<vector<int>> next;
        for(int i = 0; i < es.size(); i ++) {
            vi[es[i][0]].push_back(i);
            vi[es[i][1]].push_back(i);
            next[es[i][0]].push_back(es[i][1]);
            next[es[i][1]].push_back(es[i][0]);

        }

        int ms =  0, ans = 0;
        for(int i = 0; i < n;  i ++) {
            vector<int> dis(n, 0xffffff);
            int rst = 0;
            vector<bool> found(n, false);
            found[i] = true;
            dis[i] = 0;
            dfs(i, es, vi, thre, dis, 0, rst, found, next);


            if(rst <= ms) {
                ans = i;
                ms = rst;
            }
        }
        return ans;


    }
};

int main(){
    Solution s;
    vector<vector<int>> es{
            {0, 1, 3},
            {1,2,1},
            {1,3,4},
            {2,3,1}
    };
    cout << s.findTheCity(4, es, 4);
}
