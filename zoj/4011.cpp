#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll dp[2010][2010];
int mod = static_cast<int>(pow(10, 9)) + 7;

int main() {

	for(int i = 0; i <= 2000; i ++) {
		dp[1][i] = 1;
	}

	for (int m = 1; m <= 2000; m++) {
		for (int p = 1; p <= 2000; p++) {
			int k = p;
			while (k <= 2000) {
				dp[m + 1][k] += dp[m][p];
				dp[m + 1][k] %= mod;
				k += p;
			}
		}
	}

//	for(int i =  1900; i <= 1910; i++) {
//		for(int j = 1900; j <= 1910; j++){
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}


	int repeat;
	cin >> repeat;
	while (repeat--) {
		int n, m;
		cin >> n >> m;
		int ans = 0;
		for(int i = 1;i <= n; i++){
			ans += dp[m][i];
			ans %= mod;
		}
		cout << ans << endl;
	}


}


