#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main() {
	int repeat;
	cin >> repeat;
	while (repeat--) {
		int n;
		cin >> n;
		string s;
		cin >> s;


		if (n % 4 == 2 || n % 4 == 1) {
			cout << "-1" << endl;
			continue;
		}

		vector<int> mat(n + 1);

		if (n % 2 == 0) {    // n = 4 k
			int cur = 1;
			for (int i = 1; i < n + 1 - i; i++) {
				mat[i] = mat[n + 1 - i] = cur;
				cur = 1 - cur;
			}
		} else {    // n = 4 * k + 3
			int cur = 1;
			for (int i = 1; i < n + 1 - i; i++) {
				mat[i] = mat[n + 1 - i] = cur;
				cur = 1 - cur;
			}
			int k = (n - 3) / 4;
			if (mat[3 * k + 3] ==  cur) {
				int gg = 3 * k + 2;
				mat[gg] = 1 - mat[gg];
				mat[n + 1 - gg] = 1 - mat[n + 1 -gg];
//				mat[3 * k + 3] = 1 - mat[3 * k + 3];
//				mat[n + 1 - 3 * k - 3] = 1 - mat[n + 1 - 3 * k - 3];
			}


			mat[2 * k + 2] = mat[3 * k + 3];
			mat[3 * k + 3] = 1 - mat[3 * k + 3];
		}


		for (int i = 1; i <= n; i++) {
			char cc = s[i - 1];
			if (cc == '1') {
				if (mat[i] == 1) cout << '3';
				else cout << '4';
			} else {
				if (mat[i] == 1) cout << '1';
				else cout << '2';
			}
		}
		cout << endl;


	}

}

