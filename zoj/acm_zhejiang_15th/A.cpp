#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool isFlag(vector<int> &dat) {
	bool ans = false;
	int i = 0;
	for (i = 0; i < dat.size(); i++) {
		if (i < dat.size() - 1 && dat[i] < dat[i + 1]) {
			ans = true;
		} else {
			break;
		}
	}
	if (!ans || i == dat.size() || i == dat.size() - 1) return false;

	for(; i < dat.size() - 1; i ++) {
		if(dat[i] <= dat[i + 1]) return false;
	}
	return true;



}

int main() {
	int repeat;cin >> repeat;
	while (repeat--) {
		int n; cin >> n;
		vector<int> dat(n);
		for (int i = 0; i < n; i++) {
			cin >> dat[i];
		}
		bool ans = isFlag(dat);

		cout << (ans ? "Yes" : "No") << endl;


	}


}

