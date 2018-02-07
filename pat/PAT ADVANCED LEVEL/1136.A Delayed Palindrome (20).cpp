

#include <bits/stdc++.h>

using namespace std;

bool isPar(const string &s) {
	for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
		if (s[i] != s[j])
			return false;
	}
	return true;

}

string addp(string s) {
	string rs(s);
	for (int i = 0; i < s.length(); i++) {
		rs[i] = s[s.length() - i - 1];
	}

	string ans = s;
	int add = 0;
	for (int i = s.length() - 1; i >= 0; i--) {
		int cur = s[i] - '0' + rs[i] - '0' + add;
		ans[i] = cur % 10 + '0';
		add = cur / 10;
	}

	if (add == 1) {
		ans = "1" + ans;
	}
	cout << s << " + " << rs << " = " << ans << endl;

	return ans;

}

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < 10; i++) {
		if(isPar(s)){
			cout << s  << " is a palindromic number." << endl;
			return 0;
		}
		s = addp(s);

	}
	cout << "Not found in 10 iterations." << endl;

}