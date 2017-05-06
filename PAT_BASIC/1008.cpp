
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int *p=(int *)malloc(n*sizeof(int));
	int i,k;
	for(i=0;i<n;i++) 
	{
		scanf("%d",p+i);
	}
	m%=n;
	printf("%d",p[(n-m)%n]);
	for(i=1;i<n;i++)
	{
		printf(" %d",*(p+(i-m+n)%n));
	}
}