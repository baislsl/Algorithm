/**
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of
 * all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

 */


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		int ans = m | n;

		auto k = 1 << 30;

		while ((k & m) == (k & n)) {
			if(k == 1) return ans;
			k >>= 1;
		}

		k <<= 1;
		k -= 1;
		k = ~k;
		return ans & k;
	}
};

int main() {
	Solution s;
	cout << s.rangeBitwiseAnd(4, 5) << endl;
	cout << s.rangeBitwiseAnd(5, 7) << endl;
	cout << s.rangeBitwiseAnd(33, 64) << endl;
}

