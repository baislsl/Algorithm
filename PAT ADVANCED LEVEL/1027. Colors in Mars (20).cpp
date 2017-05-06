#include<stdio.h>
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	char a[14]="0123456789ABC";
	putchar('#');
	putchar(a[n/13]);putchar(a[n%13]);
	putchar(a[m/13]);putchar(a[m%13]);
	putchar(a[k/13]);putchar(a[k%13]);
} 
