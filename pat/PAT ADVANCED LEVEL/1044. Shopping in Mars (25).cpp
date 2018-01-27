#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,find;
	int i,j,k;
	int min,flag=0;
	scanf("%d%d",&n,&find);
	int *p=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++) scanf("%d",p+i);
	min=1000000;
	int sum=-find;
	j=0;
	for(i=0;i<n;i++)
	{
		while(sum<0)
		{
			sum+=*(p+j);
			j++;
		}
		if(sum==0)
		{
			flag=1;
			printf("%d-%d\n",i+1,j);
		}
		else
		{
			if(sum<min)
			min=sum;
		}
		j--;
		sum-=*(p+i)+*(p+j);
	} 
	if(!flag)
	{
		j=0;
		 sum=-find-min;
		 for(i=0;i<n;i++)
		 {
		 	while(sum<0)
		 	{
		 		sum+=*(p+j);
		 		j++;
			 }
			 if(sum==0)
			 {
			 	printf("%d-%d\n",i+1,j);
			 }
			 j--;
			 sum-=*(p+i)+*(p+j);
		 }
	}
}
