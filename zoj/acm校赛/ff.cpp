#include <bits/stdc++.h>
using namespace std;

const int maxn = 50005;

struct Interval {
	int l, r, id;
} a[maxn], r1, r2;

int f[maxn][2];
bitset<maxn> state[maxn][2];
int n;

int cmp(Interval i1, Interval i2) {
	return i1.l < i2.l;
}

void solve() {
	f[1][0] = 1; f[1][1] = 0;
	f[2][0] = 1; f[2][1] = 0;
	state[1][1][1] = 1; state[2][0][1] = 1; state[2][1][1] = 1; state[2][1][2] = 1;
	if (a[1].r < a[2].r) r1=a[1], r2=a[2];
	else r1=a[2], r2=a[1];
	
	for (int i=3; i<=n; i++) {
		if (a[i].l > a1.r) {
			if (f[i-1][0] < f[i-1][1]) {
				a[i][0] = f[i-1][0] + 1;
				state[i][0] = state[i-1][0];
				a[i][1] = f[i-1][0];
				state[i][1] = state[i-1][0]; state[i][1][i] = 1;
			}
			else if ()
		}
	}
}

int main() {
	
	int T;
	scanf("%d", &T);
	
	while(T--) {
		
		scanf("%d", &n);
		
		for(int i=0; i<=n; i++)
			for (int j=0; j<=1; j++)
				state[i][j].reset();
		
		for (int i=1; i<=n; i++) {
			scanf("%d%d", &a[i].l, &a[i].r);
			a[i].id = i;
		}
		
		sort(a+1, a+n+1, cmp);
		
		solve();
		
	}
	
	
	return 0;
}
