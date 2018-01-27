
#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	static int a[100003];
	int shan,max=0,pp;
	while(N--)
	{
		scanf("%d %d",&shan,&pp);
		if(shan>max) max=shan;
		a[shan]+=pp;
	}
	
	int i,mm;
	mm=1;
	for(i=1;i<=max;i++)
	{
		if(a[i]>a[mm]) mm=i;
	}
	
	printf("%d %d",mm,a[mm]);
}
