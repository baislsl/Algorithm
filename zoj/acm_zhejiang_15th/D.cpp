#include <bits/stdc++.h>

using namespace std;
using ll = long long;


// TODO:
// wrong answer


int main() {
	ll repeat;
	cin >> repeat;
	while (repeat--) {
		ll n;
		cin >> n;
		string s;
		vector<ll> dat(n);
		cin >> s;
		for (ll i = 0; i < n; i++) {
			cin >> dat[i];
		}

		ll ans = 0;

		ll pcur = 0;
		ll ncur = 0;
		for (ll i = n - 1; i >= 0; i--) {
			if (s[i] == '(') {
				if (dat[i] > 0) {
					ans += pcur * dat[i];
				} else {
					ans += ncur * dat[i];
				}
			} else {
				pcur += dat[i];
				ncur += dat[i];
				if (pcur <= 0) pcur = 0;
				if (ncur >= 0) ncur = 0;
			}
		}

		cout << ans << endl;

	}


}
