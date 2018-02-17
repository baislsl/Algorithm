


#include <bits/stdc++.h>

using namespace std;


class Solution {
public:


	int kthGrammar(int n, int k) {

		if(k == 1) return 0;
		else if(k == 2) return 1;



		int b = std::log(k) / std::log(2);
		if(k == (1 << b)) return b % 2;
		return 1 - kthGrammar(n, ((k) &(~(1 << b))));



	}
};


int main() {
	Solution s;
	// cout << s.kthGrammar(0, 4);
	for(int i = 1; i < 20; i ++ ){
		cout << s.kthGrammar(0, i);
	}
}


