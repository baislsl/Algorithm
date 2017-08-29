//
// Created by baislsl on 17-8-20.
//

/**
Given a 2D integer matrix M representing the gray scale of an image, you need to design a smoother to make the gray scale of each cell becomes the average gray scale (rounding down) of all the 8 surrounding cells and itself. If a cell has less than 8 surrounding cells, then use as many as you can.

Example 1:
Input:
[[1,1,1],
 [1,0,1],
 [1,1,1]]
Output:
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]
Explanation:
For the point (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
For the point (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
For the point (1,1): floor(8/9) = floor(0.88888889) = 0
Note:
The value in the given matrix is in the range of [0, 255].
The length and width of the given matrix are in the range of [1, 150].
 * */
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    bool isLegal(int x, int y, int a, int b){
        return x >= 0 && y >= 0 && x < a && y < b;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ret;
        int a = M.size();
        if(a == 0){
            return ret;
        }

        int b = M[0].size();

        int dir[9][2] = {
                {-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {0,0},{1, 0}, {-1, 1}, {0, 1}, {1, 1}
        };

        for(int i= 0;i<a; i++){
            vector<int> n;
            for(int j=0;j<b;j++){

                int k = 0;
                int divide = 0;
                for(int dirIndex = 0;dirIndex < 9;dirIndex++){
                    if(isLegal(i + dir[dirIndex][0], j + dir[dirIndex][1], a , b)){
                        ++divide;
                        k += M[i + dir[dirIndex][0]][j + dir[dirIndex][1]];
                    }
                }
                n.push_back(k / divide);
            }

            ret.push_back(n);
        }

        return ret;
    }
};













