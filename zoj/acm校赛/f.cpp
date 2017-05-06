#include<bits/stdc++.h>

using namespace std;

int main(){
	int repeat;
	scanf("%d", &repeat);
	char a[1020];
	while(repeat--){
		
		scanf("%s", a);
		string s = a;
		int size = s.size();
		int cnt = 0;
		for(int i=0;i<size - 2;i++){
			if(s[i] == 'c' && s[i+1] == 'a' && s[i+2] == 't')
				cnt ++;
			else if(s[i] == 'd' && s[i+1] == 'o' && s[i+2] == 'g')
				cnt ++; 
		}
		printf("%d\n", cnt);
	}
}
