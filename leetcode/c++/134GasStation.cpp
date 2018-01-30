/**
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel
 from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once,
 otherwise return -1.

Note:
The solution is guaranteed to be unique.
 */
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		vector<int> sub(gas.size());
		for (int i = 0; i < gas.size(); i++) {
			sub[i] = gas[i] - cost[i];
		}

		int i = 0;
		bool exit = false;
		while (i < sub.size() && !exit) {
			while (i < sub.size() && sub[i] < 0) {
				i++;
			}
			int ans = i;
			int cnt = 0;
			while (i < sub.size() && cnt >= 0) {
				cnt += sub[i];
				i++;
				if (i >= sub.size()) {
					exit = true;
					i -= sub.size();
				}
				if (i == ans) {
					if (cnt >= 0) return ans;
					return -1;
				}
			}
		}

		return -1;


	}
};

int main() {
	vector<int> gas{2, 2, -5, 4, -3};
	vector<int> cost(gas.size(), 0);
	Solution s;
	cout << s.canCompleteCircuit(gas, cost) << endl;


	/**
	 * []
[]
	 */

	vector<int> gas2{5, 0, 9, 4, 3, 3, 9, 9, 1, 2};
	vector<int> cost2{6, 7, 5, 9, 5, 8, 7, 1, 10, 5};

	cout << s.canCompleteCircuit(gas2, cost2) << endl;

}

