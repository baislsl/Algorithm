
#include<stdio.h>
int main()
{
	int jia,yi;
	jia=yi=0;
	int a1,a2,b1,b2;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d %d %d %d",&a1,&a2,&b1,&b2);
		if(a2==a1+b1&&b2!=a2) jia++;
		else if(b2==a1+b1&&b2!=a2) yi++;
	}
	printf("%d %d",yi,jia);
}