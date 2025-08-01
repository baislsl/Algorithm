//
// Created by baislsl on 2025/7/12.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("/Users/baislsl/cpp/Algorithm/codeforces/input.txt", "r", stdin);

    int T;
    cin >> T;
    while (T--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        long cost = 0;
        set<pair<int, int> > qe;
        qe.insert(make_pair(0, a));
        set<int> ca;
        int rst = -1;
        while (!qe.empty()) {
            auto v = qe.begin();
            long cost = v->first;
            int n = v->second;
            qe.erase(qe.begin());

            if (ca.count(n)) continue;
            ca.insert(n);

            if (n == b) {
                rst = cost;
                break;
            }
            for (auto [ncost, nn]: {make_pair(cost + x, n + 1), make_pair(cost + y, n ^ 1)}) {
                if (nn > b + 1) continue;
                qe.insert(make_pair(ncost, nn));
            }
        }
        cout << rst << endl;
    }
}
