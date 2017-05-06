
#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int n;
	int p,a[100002],temp;
	double b[100002];
	scanf("%d %d",&n,&p);
	int i,j;
	for(i=0;i<n;i++)  scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),compare);
	for(i=0;i<n;i++) b[i]=a[i]*1.0/p;
	int max=1;
	j=0;
	for(i=0;i<n-max;i++)
	{
	 	while(j<n&&b[j]<=a[i]+0.00001) j++;
	 	if(max<j-i) max=j-i;
	 	j--;
	}
	 printf("%d",max);
}