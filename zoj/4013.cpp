#include <bits/stdc++.h>

using namespace std;

int main() {
	int repeat;
	cin >> repeat;
	while (repeat--) {
		int n ;
		cin >> n;
		vector<bool> flag(static_cast<int>(pow(10, 6)) + 100, false);

		int k, ans;
		for(int i = 0;i < n; i ++) {
			cin >> k;
			if(flag[k]) ans = k;
			flag[k] = true;
		}

		for(int i = 0;i < n; i ++) {
			cin >> k;
			if(flag[k]) ans = k;
			flag[k] = true;
		}

		cout << ans << endl;
	}
}


