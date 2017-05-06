
#include<stdio.h>
#include<math.h>
int prime(int n)
{
	int i;
	int g=sqrt(n);
	for(i=2;i<=g;i++) if(n%i==0) break;
	if(i>g) return 1;
	else return 0; 
}
int main()
{
	int begin,end;
	int count=0,i,sum=0;
	scanf("%d%d",&begin,&end);
	for(i=2;;i++)
	{
		if(prime(i)) 
		{
			count++;
			if(count>=begin&&count<=end)
			{   sum++;
				printf("%d",i);
			
				if(count==end) break;
				if(sum%10) printf(" ");
				else printf("\n");
			}
			if(count>end) break;
		}
	}
} 