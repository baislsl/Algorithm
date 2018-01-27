#include<stdio.h>
#include<stdlib.h>
int *love;
int rank[201];
int max=0;
int m;
void find(int *a,int current,int rankk,int length)
{
	while(current!=m)
	{
		if(length+m-current<=max) break;
		if(rank[a[current]]>=rankk) 
		{
			find(a,current+1,rank[a[current]],length+1);
		}
		current++;
	}
	if(length>max) max=length;
}
int main()
{
	int n,i;
	getchar();getchar();
	scanf("%d",&n);
	love=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++) 
	{
		scanf("%d",love+i);
		rank[*(love+i)]=i+1;
	}
	scanf("%d",&m);
    int *a=(int *)malloc(m*sizeof(int));
	for(i=0;i<m;i++) scanf("%d",a+i);
	find(a,0,1,0);
	printf("%d",max);
}
