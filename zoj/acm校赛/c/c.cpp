#include <bits/stdc++.h>
using namespace std;

vector<int> leap;

int main() {
	
	for (int i=2000; i<=9999; i++) {
		if (i%4 == 0 && i%100 || i%400 == 0)
			leap.push_back(i);
	}
	
	for (int i=0; i<leap.size(); i++) {
		printf("%d\n", leap[i]);
	}
	
	return 0;
}
