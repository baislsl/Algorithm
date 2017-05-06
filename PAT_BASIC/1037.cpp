
#include<stdio.h>
void ff(long int a,long int b)
{
	long int c=a-b;
	int a0,c0,b0;
	c0=c%29;
	c/=29;
	b0=c%17;
	a0=c/17;
	printf("%d.%d.%d",a0,b0,c0);
}
int main()
{
	int a1,a2,b1,b2,c1,c2;
	scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
	long int count1,count2;
	count1=c1+29*(b1+17*a1);
	count2=c2+29*(b2+17*a2);
	if(count1>count2) 
	{
		printf("-");
		ff(count1,count2);
	}
	else ff(count2,count1);
}