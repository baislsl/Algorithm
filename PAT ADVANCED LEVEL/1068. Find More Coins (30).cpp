#include<stdio.h>
#include<stdlib.h>
int flag=0,find,num_x;
int *a,n;
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
void add(int sum,int place,int *num,int num_x)
{
	sum+=a[place];
	num[num_x]=place;
	if(sum==find) 
	{
		int i;
		flag=1;
		printf("%d",a[num[0]]);
		for(i=1;i<=num_x;i++) printf(" %d",a[num[i]]);
	}
	else if(sum<find&&!flag)
	{
		if(place!=n-1) 
		{
			add(sum,place+1,num,num_x+1);
			add(sum-a[place],place+1,num,num_x);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&find);
	int i;
	int *num=(int *)malloc(n*sizeof(int)); 
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		scanf("%d",a+i);
	}
	qsort(a,n,sizeof(int),compare);
    add(0,0,num,0);
	if(!flag) printf("No Solution");
} 



