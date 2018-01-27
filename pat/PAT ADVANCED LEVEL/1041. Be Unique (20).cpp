#include<stdio.h>
#include<stdlib.h>
int main()
{
	static int a[10002],n,i;
	scanf("%d",&n);
	int *p=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++) 
	{
		scanf("%d",p+i);
		a[*(p+i)]++;
	}
	for(i=0;i<n;i++)
	{
		if(a[*(p+i)]==1) 
	    {
	    	printf("%d",*(p+i));
	    	break;
		}
	}
	if(i==n) printf("None");
}
