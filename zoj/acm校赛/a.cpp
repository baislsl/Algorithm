#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	
	int T;
	scanf("%d", &T);
	
	while(T--) {
		int x, y, a, b;
		scanf("%d%d%d%d", &x, &y, &a, &b);
		
		int cnt = 0;
		int loop = 0;
		
		while(1) {
			loop ++;
			if (loop >= 200000) {
				cnt = -1;
				break;
			}
			if (a>=x) {
				cnt ++;
				a -= x;
				a++, b++;
			}
			else if (b>=y) {
				cnt ++;
				b -= y;
				a++, b++;
			}
			else break;
		}
		
		if (cnt == -1) printf("INF\n");
		else printf("%d\n", cnt);
	}
	
	
	
	return 0;
}
