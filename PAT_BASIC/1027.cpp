
#include<stdio.h>
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	getchar();
	char c=getchar();
	for(i=1;;i++)
	{
		if(n<2*i*i-1) break;
	}
	int cha;
	int a1=2*i*i-1-n;
	int a2=n-2*(i-1)*(i-1)+1;
	int m;
	
		m=n-a2;
		i=i-1;
		cha=a2;

	for(j=1;j<=i;j++)
	{
		for(k=1;k<=j-1;k++) printf(" ");
		for(k=1;k<=2*(i-j)+1;k++) putchar(c);
		printf("\n");
	}
	for(j=1;j<=i-1;j++)
	{
		for(k=1;k<=i-1-j;k++) printf(" ");
		for(k=1;k<=2*j+1;k++) putchar(c);
		printf("\n");
	}
	printf("%d",cha);
} 