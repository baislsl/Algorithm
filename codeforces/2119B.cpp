//
// Created by baislsl on 2025/7/12.
//
#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("/Users/baislsl/cpp/Algorithm/codeforces/input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int px, py, qx, qy;
        cin >> px >> py >> qx >> qy;
        vector<int> ar(n);
        for (int i = 0; i < n; i++) cin >> ar[i];
        double dis = sqrt(pow(px - qx, 2) + pow(py - qy, 2));

        sort(ar.rbegin(), ar.rend());
        double mi = ar[0], mx = ar[0];
        for (int i = 1; i < n; i++) {
            mx += ar[i];
            mi -= ar[i];
        }
        mi = max(mi, 0.);
        bool ans = mi <= dis && dis <= mx;
        cout << (ans ? "YES" : "NO") << endl;

    }
}