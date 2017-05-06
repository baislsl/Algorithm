
#include<stdio.h>
int main()
{
	char cc;
	int n;
	int i,j;
	scanf("%d  %c",&n,&cc);
	i=n;
	if(i%2) j=i/2+1;
	else j=i/2;
	
	int k,m;
	for(k=1;k<=i;k++) putchar(cc);
	putchar('\n');
	for(k=1;k<=j-2;k++) 
	{
		putchar(cc);
		for(m=1;m<=i-2;m++) putchar(' ');
		putchar(cc);
		putchar('\n');
	}
	for(k=1;k<=i;k++) putchar(cc);
} 