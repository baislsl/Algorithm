
#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	double b[100003];
	int i=1;
	double sum=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&b[i]);
		sum+=i*1.0*(n-i+1)*1.0*b[i];
	}
	printf("%.2lf",sum);
}