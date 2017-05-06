#include<bits/stdc++.h>

#define ll long long 

const int maxn = 1020;
ll dive = 1000000000+7;

ll p2[2020];
int m,n;
int mat[maxn][maxn];
int cnt[maxn][maxn][2];

struct one{
	int key;
	int col, row;
}s[maxn][maxn];

struct one tmp[maxn];

void init(){
	ll p = 1;
	for(int i=0;i<2020;i++){
		p2[i]  = p;
		p =(p*2)%dive;
	}
}

int cmp(const void *pa ,const void *pb){
	return ((struct one*)pa)->key - ((struct one*)pb)->key;
}

int cmp2(const void *pa ,const void *pb){
	return ((struct one*)pb)->key - ((struct one*)pa)->key;
}

void fcol(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tmp[j] = s[j][i];
		}
		qsort(tmp, m, sizeof(struct one), cmp2);
		int j=0;
		while(j < m){
			int key = tmp[j].key;
			int begin = j;
			while(j < m - 1 && tmp[j+1].key == key) j++;
			int end = j;
			for(int i=begin; i<=end ;i++){
				cnt[tmp[i].row][tmp[i].col][0] = begin;
			}
			j++;
		}
	}
}

void frow(){
	for(int i_=0;i_<m;i_++){
		for(int j=0;j<n;j++){
			tmp[j] = s[i_][j];
		}
		qsort(tmp, n, sizeof(struct one), cmp);
		int i=0;
		while(i < n){
			int key = tmp[i].key;
			int begin = i;
			while(i < n - 1 && tmp[i+1].key == key) i++;
			int end = i;
			for(int j=begin; j<=end ;j++){
				cnt[tmp[j].row][tmp[j].col][1] = begin;
			}
			i++;
		}
	}
}

int main(){
	int repeat;
	init();
	scanf("%d", &repeat);
	while(repeat--){
		scanf("%d%d", &m,&n);
		int tm = m, tn = n;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				scanf("%d", &(mat[i][j]));
				s[i][j].key = mat[i][j];
				s[i][j].row = i;
				s[i][j].col = j;
			}
		}
		fcol(); frow();
		ll sum = 0;
		//printf("%d %d", m ,n);
		for(int i=0;i<tm;i++){
			for(int j=0;j<tn;j++){
			//	printf("%d %d", cnt[i][j][0],cnt[i][j][1]);
				sum = (sum + p2[cnt[i][j][0] + cnt[i][j][1]])%(dive);
			}
		}
		printf("%lld\n", sum);
	}
}
