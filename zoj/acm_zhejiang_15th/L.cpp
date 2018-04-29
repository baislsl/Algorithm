#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	ll repeat;
	cin >> repeat;
	while (repeat--) {
		ll n, m;
		cin >> n >> m;
		vector<pair<string, ll> > dat(n);
		for (ll i = 0; i < n; i++) {
			string s;
			ll value;
			cin >> s >> value;

			dat[i] = make_pair(s, value);
		}


		sort(dat.begin(), dat.end(),
			 [](const pair<string, ll> &a, const pair<string, ll> &b) -> bool {
				 return a.second == b.second ? (a.first < b.first) : a.second > b.second;
			 });


		string ans = "";
		ll cnt = 0;
		for (ll i = 0; i < m; i++) {
			cnt += (m - i) * dat[i].second;
			ans += " " + dat[i].first;
		}

		cout << cnt << ans << endl;

	}

}

