#include <bits/stdc++.h>


using namespace std;
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

bool a[7][7];
bool exist[7];
bool ans;

void dfs(int index){
	if(index == 7){
		ans = true;
		return;
	}
	for(int i=0;i<7;i++){
		if(a[index][i] == true && exist[i] == false){
			exist[i] = true;
			dfs(index+1);
			exist[i] = false;
		}
	}
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	int repeat;
	scanf("%d", &repeat);
	while(repeat--){
		int n;
		memset(a, true, sizeof(a));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char s[10];
			int num;
			scanf("%d %s", &num, s);
			
			cout << num << " " << s << endl;
			
//			for(int i=0;i<7;i++){
//				if(s[i] == '1'){
//					for(int j=0;j<7;j++){
//						if(seg7[num-1][j] == 1){
//							a[i][j] = true;
//						}
//					}
//				}
//			}
			
			for(int i=0;i<7;i++){
				if(s[i] == '1'){
					for(int j=0;j<7;j++){
						if(seg7[num-1][j] == 0){
							a[i][j] = false;
						}
					}
				}
			}
		}


		int sor[7];
		for(int i=0;i<7;i++)
		for(int j=0;j<7;j++){
			if(a[i][j] ) sor[i]++;
		}
		memset(exist, false, sizeof(exist));
		ans = false;
		dfs(0);
		
		if(ans){
			puts("YES");
		}else 
			puts("NO");
	}
}
