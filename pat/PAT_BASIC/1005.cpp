
#include<stdio.h>
#include<stdlib.h>
int compare(const void *pa,const void *pb)
{
	return *(int *)pb-*(int *)pa;
}
int main()
{
    static int num[100002];
	int n;
	scanf("%d",&n);
	int *p=(int *)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
	{
	     scanf("%d",p+i);
		 num[*(p+i)]=1;	
	}
	qsort(p,n,sizeof(int),compare);
	for(i=0;i<n;i++)
	{ 
	    int temp=*(p+i);
		while(temp!=1)
		{
			if(temp%2) temp=(3*temp+1)/2;
			else temp/=2;
			num[temp]=0;
		}	
	}	
	int flag=0;
	for(i=0;i<n;i++)
	{
		if(num[*(p+i)]) {
			if(flag) printf(" ");
			flag=1;
			printf("%d",*(p+i));
		}
	}
} 