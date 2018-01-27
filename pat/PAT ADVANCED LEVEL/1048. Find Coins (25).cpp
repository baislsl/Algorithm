#include<stdio.h>
#include<stdlib.h>
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int n,find;
	scanf("%d%d",&n,&find);
	int *a=(int *)malloc(n*sizeof(int));
	int i,j,k;
	for(i=0;i<n;i++) scanf("%d",a+i);
	qsort(a,n,sizeof(int),compare);
	j=n-1;
	for(i=0;i<j;i++)
	{
		while(a[j]+a[i]>find) 
		{
			j--;
		    if(j<=i) 
		    {
		    	printf("No Solution");
		    	exit(0);
			}
		}
		if(a[j]+a[i]==find) 
		{
			printf("%d %d",a[i],a[j]);
			exit(0);
		}
	}
	printf("No Solution");
}
