#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int*)a-*(int *)b;
}
int main()
{
	int *a,n,m,i;
	scanf("%d%d",&n,&m);
	int sum=n*m;
	a=(int *)malloc(n*m*sizeof(int));
	for(i=0;i<sum;i++) scanf("%d",a+i);
	qsort(a,sum,sizeof(int),compare);
	printf("%d",a[sum/2]);
}
