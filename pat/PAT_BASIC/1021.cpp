
#include<stdio.h>
int main(){
	char a[10];
	int i,b[10]={0,0,0,0,0,0,0,0,0,0};
	char c;
	while((c=getchar())!='\n'){
		b[c-'0']++;
	}
	for(i=0;i<=9;i++){
		if(b[i]!=0) printf("%d:%d\n",i,b[i]);
	}
} 
