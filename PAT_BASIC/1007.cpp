
#include<stdio.h>
#include<math.h>
bool fact(int i)
{
	int k,p=(int)sqrt(i);
	for(k=2;k<=p;k++)
	{
		if(i%k==0) break;
	}
	if(k==p+1) return true;
	return false;
}
int main()
{
	int n,i,count=0;
	scanf("%d",&n);
	for(i=3;i<=n-2;i++)
	{
		if(fact(i)&&fact(i+2)) count++;
	}
	printf("%d",count);
} 