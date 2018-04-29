#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	int repeat;
	cin >> repeat;
	while (repeat--) {
		int n , b;
		cin >> n >> b;
		bool ans = false;
		while(n --) {
			int k; cin >> k;
			if((k + b) % 7 ==0) ans = true;
		}

		cout << (ans ? "Yes" : "No") << endl;
	}

}

