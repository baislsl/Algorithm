#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	int repeat;
	cin >> repeat;
	while (repeat--) {
		int n, m;
		cin >> n >> m;

		int wInd = -1;
		vector<int> dat(n);
		for (int i = 0; i < n; i++) {
			char cc;
			cin >> cc;
			if (cc == 'W') {
				wInd = i;
				dat[i] = -1;
			} else {
				int pow;
				if (cc == 'C') pow = 0;
				else if (cc == 'B') pow = 1;
				else pow = 2;
				int k;
				cin >> k;
				dat[i] = pow * m + k - 1;
			}
		}

		if (wInd == -1) {
			if (n >= 2 && dat[0] > dat[1]) {
				cout << 1 << endl;
			} else {
				cout << 3 * m - (n - 1) << endl;
			}

		} else if (n >= 2 && dat[0] > dat[1] && wInd != 1 && wInd != 0) {
			cout << 1 << endl;
		} else {
			int ans = 0;
			if (wInd == 0) {
				if (n == 1) {
					ans = 3 * m;
				} else {
					ans = dat[1];
				}

			} else {
				if (wInd == n - 1 && n != 1) {
					ans = 3 * m - dat[n - 2] - 1;
					if (n == 2) ans += 1;
				} else {
					ans = dat[wInd + 1] - dat[wInd - 1] - 1;
					if (wInd == 1) {
						ans += 1;
					}

				}
			}

			cout << ans << endl;


		}


	}


}

