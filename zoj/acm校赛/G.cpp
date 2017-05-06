#include <bits/stdc++.h>

typedef struct _cpx{
	int x;
	char s[8];
}cpx;

int seg7[][7] = {
					{1,0,0,1,1,1,1},//1
					{0,0,1,0,0,1,0},//2
					{0,0,0,0,1,1,0},//3
					{1,0,0,1,1,0,0},//4
					{0,1,0,0,1,0,0},//5
					{0,1,0,0,0,0,0},//6
					{0,0,0,1,1,1,1},//7
					{0,0,0,0,0,0,0},//8
					{0,0,0,0,1,0,0},//9
				};

int equal[9][9];
int count0[9] = {2,5,5,4,5,6,3,7,6};

int countEqual() {
	for (int i=0; i<9; i++) {
		for(int j=i+1; j<9; j++) {
			for(int k=0; k<7; k++) {
				if(seg7[i][k] == 0 && seg7[j][k] == 0) {
					equal[i][j] ++;
					equal[j][i] ++;
				}
			}	
		}
	}
}

int countZero(char s[8]) {
	int res = 0;
	for(int i=0; i<7; i++) {
		if(s[i] == '0')
			res ++;
	}
	return res;
}

int judge(cpx* c, int n) {
	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			int cnt = 0;
			if(count0[c[i].x-1] != countZero(c[i].s) )
				return 0;  
			for(int k=0; k<7; k++) {
				if(c[i].s[k]=='0' && c[j].s[k]=='0')
					cnt ++;
			}
			if(cnt != equal[c[i].x-1][c[j].x-1])
				return 0;
		}
	}
	return 1;
}

int main() {
	int repeat;
	scanf("%d", &repeat);
	int n, yes;
	countEqual();
	while(repeat--) {
		scanf("%d", &n);
		cpx c[n];
		for (int i=0; i<n; i++) {
			scanf("%d %s", &c[i].x, c[i].s); 
		}
		if(judge(c, n))
			printf("YES\n");
		else 
			printf("NO\n");
	}
	
	return 0;
}
