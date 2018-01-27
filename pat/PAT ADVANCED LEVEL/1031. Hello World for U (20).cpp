#include<stdio.h>
#include<string.h>
int main()
{
	int n,m=0;
	char a[81];
	gets(a);
	n=strlen(a)+2;
	while(n>=3)
	{
		n-=2;
		m++;
		if(m>n) break;
	}
	m--;
	n+=2;
	int i,j;
	for(i=1;i<m;i++)
	{
		putchar(a[i-1]);
		for(j=0;j<n-2;j++) putchar(' ');
		putchar(a[n+2*m-2-i]);
		putchar('\n');
	}
	for(i=m-1;n--;i++) putchar(a[i]);
}

