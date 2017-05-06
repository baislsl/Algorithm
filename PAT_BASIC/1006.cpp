
#include<stdio.h>
int main(void)
{
	int n,i;
	scanf("%d",&n);
	int a,b,c;
	a=n%10;
	b=n/10%10;
	c=n/100;
	for(i=1;i<=c;i++) printf("B");
	for(i=1;i<=b;i++) printf("S");
	for(i=1;i<=a;i++) printf("%d",i);
} 