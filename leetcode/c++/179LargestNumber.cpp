/**

 Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
 */

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
	string largestNumber(vector<int> &nums) {
		vector<string> sn(nums.size());
		std::transform(nums.begin(), nums.end(), sn.begin(),
					   [](const int a) -> string {
						   return std::to_string(a);
					   });
		//		for(auto s : sn ) cout << s << " ";

		std::sort(sn.begin(), sn.end(),
				  [](const string &a, const string &b) -> bool {
					  auto a1 = a + b, b1 = b + a;
					  return a1 > b1;
				  });
		string ans;
		for (auto &s : sn)
			ans += s;

		int i = 0;
		while (i < ans.length() - 1 && ans[i] == '0') i++;
		ans = ans.substr(i);

		return ans;
	}

};

int main() {
	Solution s;
	vector<int> nums{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
					 0};
//	vector<int> nums{3, 30, 34, 5, 9};
	cout << s.largestNumber(nums) << endl;
}






