#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool b[1000000];
int a[1000000];
int main()
{
	int n;
	memset(b,true,sizeof(b));
	scanf("%d",&n);
	int i,j;
	int min,max;
	scanf("%d",&max);
	a[0]=max;
	for(i=1;i<n;i++)
	{
		scanf("%d",a+i);
		if(a[i]<max)
		{
			b[i]=false;
		}
		else max=a[i];
	}
	min=a[n-1];
	for(i=n-2;i>=0;i--)
	{
		if(a[i]>min)
		{
			b[i]=false;
		}
		else min=a[i];
	}
	int flag=0,count=0;
	for(i=0;i<n;i++)
	{
		if(b[i])
		{
			count++;
		} 
	}
	printf("%d\n",count);
	for(i=0;i<n;i++)
	{
		if(b[i])
		{
						if(flag)
			{
				printf(" %d",a[i]);
			} 
			else
			{
				flag=1;
				printf("%d",a[i]);
			}
		}
	}
	putchar('\n');
}
