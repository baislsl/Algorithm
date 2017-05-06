#include<stdio.h>
#include<math.h>
int prime(int n)       //默认n为1时也返回1； 
{
	int i;
	int g=(int)sqrt(n);
	for(i=2;i<=g;i++)
	{
		if(n%i==0) break;
	}
	if(i>g) return 1;
	else return 0;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	int a[1000][2];
	int ax=0;
	if(n==1) printf("1=1");
	else
	{
		printf("%d=",n);
		for(i=2;!prime(n);i++)
		{
			if(prime(i))
			{
				if(n%i==0) 
				{
					a[ax][0]=i;
					a[ax][1]=0;
					do
					{
						n/=i;
						a[ax][1]++;
					}while(n%i==0);
					ax++;
				}
			}
		}
		if(n!=1)
		{
			a[ax][0]=n;
			a[ax][1]=1;
			ax++;
		}
		for(i=0;i<ax-1;i++)
		{
			if(a[i][1]!=1)
			{
				printf("%d^%d*",a[i][0],a[i][1]);
			}
			else printf("%d*",a[i][0]);
		}
		if(a[ax-1][1]!=1) printf("%d^%d",a[i][0],a[i][1]);
		else printf("%d",a[i][0]);
	}
	 
}





