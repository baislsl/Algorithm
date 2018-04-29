#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	int repeat;
	cin >> repeat;
	while (repeat--) {
		int n;
		cin >> n;
		vector<int> f(n);
		vector<int> l(n);
		vector<int> r(n);


		int maxK = 0;

		for (int i = 0; i < n; i++) {
			cin >> f[i];
			maxK = max(maxK, f[i]);
		}
		for (int i = 0; i < n; i++) {
			cin >> l[i];
			cin >> r[i];
		}

		vector<int> last(n + 1, -1);
		vector<int> next(n);
		for (int i = 0; i < n; i++) {
			next[i] = last[f[i]];
			last[f[i]] = i;
		}


		vector<int> ans(n);
		for (int i = 1; i <= maxK; i++) {
			int cur = last[i];
			int pre = last[i - 1];
			int curMin = INT_MIN;
			int curMax = INT_MAX;

			while (cur != -1) {
				l[cur] = max(curMin, l[cur]);
				curMin = max(curMin, l[cur]);
				while (pre != -1 && pre >= cur) {
					pre = next[pre];
				}
				if (pre != -1) {
					l[cur] = max(ans[pre] + 1, l[cur]);
				}
				ans[cur] = l[cur];
				cur = next[cur];
			}
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}


	}


}

