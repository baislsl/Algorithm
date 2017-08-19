//
// Created by baislsl on 17-8-14.
//
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct one {
    int profit;
    int last;
    int ddl;
};

/**
 * dp[i][j], i -> day, j -> index of data
 *
 * dp[i][j] = max (dp[i-1][j], dp[i-day(j)][j] + profit(j) );
 *
 * @return
 */
#define MAX_DAY 100000
int dp[MAX_DAY][51];

int main() {

    int day_max = 0;
    int n;
    cin >> n;
    vector<one> data;
    for (int i = 0; i < n; i++) {
        struct one tmp;
        cin >> tmp.profit >> tmp.last >> tmp.ddl;
        data.push_back(tmp);
        day_max = max<int>(tmp.ddl, day_max);
    };
    std::sort(data.begin(), data.end(),
              [](const one &a1, const one &a2) -> bool {
                  return a1.ddl < a2.ddl;
              }
    );

//    for (int i = 0; i < n; i++) {
//        cout << data[i].ddl << " " << endl;
//    }

    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= day_max; i++) {
            if (i > data[j].ddl) {
                dp[i][j + 1] = dp[i-1][j + 1];
                continue;
            }
            int tmp = 0;
            if (i < data[j].last)
                tmp = 0;
            else
                tmp = dp[i - data[j].last][j] + data[j].profit;
            dp[i][j + 1] = max<int>(dp[i][j], tmp);
        }

    }
//    for (int j = 0; j < n; j++) {
//        for (int i = 0; i < day_max; i++) {
//            cout << dp[i + 1][j + 1] << " ";
//        }
//        cout << endl;
//    }

    cout << dp[day_max][n];


};
