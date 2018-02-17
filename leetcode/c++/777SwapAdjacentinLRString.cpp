
#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	bool canTransform(string start, string end) {
		string ss, ed;
		if (start.size() != end.size()) return false;
		int n = start.size();
		for (int i = 0; i < n; i++) {
			if (start[i] != 'X') ss += start[i];
			if (end[i] != 'X') ed += end[i];
		}
		if(ss != ed) return false;

		int cs, ce;
		cs = ce = 0;
		for (int i = 0; i < n; i++) {
			if (start[i] == 'R') cs += 1;
			if (end[i] == 'R') ce += 1;
			if (cs < ce) return false;
		}

		cs = ce = 0;
		for (int i = 0; i < n; i++) {
			if(start[i] == 'L') cs += 1;
			if(end[i] == 'L') ce += 1;
			if(ce < cs) return false;
		}
		return true;


	}
};

int main() {

	Solution s;
	cout << std::boolalpha << s.canTransform("XXRXXLXXXX",
											 "XXXXRXXLXX");
}
