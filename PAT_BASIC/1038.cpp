
#include<stdio.h>
int main()
{
	static int dd[101];
	int n,temp;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&temp);
		dd[temp]++;
	}
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&temp);
		printf("%d",dd[temp]);
		if(n) printf(" ");
	}
}