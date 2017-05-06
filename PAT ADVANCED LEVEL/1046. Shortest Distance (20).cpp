#include<stdio.h>
#include<stdlib.h> 
int main()
{
	int *p,n,i,j;
	scanf("%d",&n);
	int sum=0;
	p=(int *)malloc(2*n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",p+i);
	    sum+=*(p+i);
	}
	int repeat;
	int a;
	int exit1,exit2;
	scanf("%d",&repeat);
	while(repeat--)
	{
	    a=0;
		scanf("%d%d",&exit1,&exit2);
		exit1--;exit2--;
		if(exit1<exit2)
		{
			for(i=exit1;i<exit2;i++) a+=*(p+i);
		}
		else 
		{
			for(i=exit2;i<exit1;i++) a+=*(p+i);
		}
		printf("%d\n",2*a>sum?sum-a:a);
	}
}
