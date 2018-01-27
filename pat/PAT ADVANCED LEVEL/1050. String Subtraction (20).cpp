#include<stdio.h>
#include<string.h>
int main()
{
	int a[300];
	char s1[10001],s2[10001];
	gets(s1);gets(s2);
	int i=0;
	for(i=0;i<300;i++) a[i]=1;
	i=0;
	while(s2[i]) a[s2[i++]]=0;
	i=-1;
	while(s1[++i]) if(a[s1[i]]) putchar(s1[i]);
}
