#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	int repeat;
	cin >> repeat;
	while(repeat --) {
		int n; cin >> n;
		vector<int> a(n), b(n);
		for(int i = 0;i < n; i++) {
			cin >> a[i];
		}
		for(int i = 0;i < n; i++) {
			cin >> b[i];
		}

		map<int, int> cnt;

		for(int i = 0;i < n; i++) {
			a[i] -= b[i];
			cnt[a[i]]++;
		}
		int ans = 0;

		for(auto &p : cnt) {
			ans = max(ans, p.second);
		}

		cout << ans << endl;


	}



}

