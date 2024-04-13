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
    vector<string>
    watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level) {
        set<int> exi;
        exi.insert(id);
        set<string> se;
        set<int> cur, next;
        cur.insert(id);
        map<string, int> freq;
        while (level != 0) {
            next.clear();
            for (int i  : cur) {

                for (string &s : watchedVideos[i]) {
                    se.insert(s);
                }

                for (int f : friends[i]) {
                    if (exi.find(f) != exi.end() and 1== 0) {
                        continue;
                    }
                    exi.insert(f);
                    next.insert(f);
                }
            }

            level -= 1;
            swap(cur, next);
        }

        for (int i : cur) {
            for(const string &v : watchedVideos[i]) {
                //if (se.find(v) != se.end()) continue;
                freq[v]++;
            }
        }
        vector<std::pair<int, string>> rst;
        for (pair<string, int> p : freq) {
            rst.emplace_back(pair<int, string>(p.second, p.first));
        }
        sort(rst.begin(), rst.end());

        vector<string> ans;
        for (auto p: rst) {
            ans.push_back(p.second);
        }
        return ans;

    }
};