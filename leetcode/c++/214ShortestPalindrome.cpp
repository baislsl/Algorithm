//
// Created by baislsl on 17-8-30.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {

private:

public:
    string shortestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string tmp = s + "#" + r;
        vector<int> v(tmp.size(), 0);

        for(int i=1;i<tmp.size();i++){
            int j = v[i - 1];
            while(j > 0 && tmp[i] != tmp[j]){
                j = v[j - 1];
            }
            v[i] = j;
            if(tmp[i] == tmp[j]) ++ v[i];
        }
        return r.substr(0, s.size() - v[tmp.size() - 1]) + s;




    }
};