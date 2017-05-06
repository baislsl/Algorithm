#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)b-*(int *)a;
}
int main()
{
	int a[2][100002],b[2][100002];
	int n,a0,a1,b0,b1;
	a0=a1=b0=b1=0;
	int temp;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&temp);
		if(temp>0) a[0][a0++]=temp;
		else a[1][a1++]=-temp;
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&temp);
		if(temp>0) b[0][b0++]=temp;
		else b[1][b1++]=-temp;
	}
	
	qsort(a[0],a0,sizeof(int),compare);
	qsort(a[1],a1,sizeof(int),compare);
	qsort(b[0],b0,sizeof(int),compare);
	qsort(b[1],b1,sizeof(int),compare);
	
	int put=0;
	if(a0>b0) a0=b0;
	int i;
	for(i=0;i<a0;i++)
	{
		put+=a[0][i]*b[0][i];
	}
	if(a1>b1) a1=b1;
	for(i=0;i<a1;i++) put+=a[1][i]*b[1][i];
	printf("%d",put);
	
}
