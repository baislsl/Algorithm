#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll bs(vector<ll> &a, double p, ll begin, ll end) {
	if (begin == end)
		return end;
	if (begin == end - 1) {
		if (a[begin] >= p) return begin;
		else return begin + 1;
	} else if (begin == end - 2) {
		if (a[begin] >= p) return begin;
		else if (a[begin + 1] >= p) return begin + 1;
		else return begin + 2;
	}


	ll mid = (begin + end) / 2;
	if (a[mid] < p) {
		return bs(a, p, mid + 1, end);
	} else {
		return bs(a, p, begin, mid + 1);
	}

}

int main() {
	ll repeat;
	cin >> repeat;
	while (repeat--) {
		ll n, m;
		cin >> n >> m;
		vector<ll> a(n);
		vector<pair<ll, ll> > p(m);
		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (ll i = 0; i < m; i++) {
			cin >> p[i].first;
			p[i].second = i;
		}

		sort(p.begin(), p.end());
		vector<ll> cp(m + 1, 0);
		vector<ll> tp(m, 0);
		for (ll i = 1; i <= m; i++) cp[i] = p[i - 1].second + 1 + cp[i - 1];
		for (ll i = 0; i < m; i++) tp[i] = p[i].first;

		ll ans = 0;
		ll mod = 1000000000;
		for (ll i = 0; i < n; i++) {
			ll pre = m;
			ll cur = 1;

			while (pre != 0) {
				double pp = pow(a[i], 1.0 / cur);
				ll ind = bs(tp, pp, 0, m);
				ans += (cp[pre] - cp[ind]) * (a[i] / (cur));
				ans %= mod;
				pre = ind;
				++cur;
			}


		}

		cout << ans << endl;


	}


}

