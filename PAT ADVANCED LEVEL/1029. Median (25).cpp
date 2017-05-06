#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,m,i;
	scanf("%d",&n);
	long *p=(long *)malloc((n+1)*sizeof(long));
	for(i=0;i<n;i++) scanf("%ld",p+i);
	scanf("%d",&m);
	long *q=(long *)malloc((m+1)*sizeof(long));
	for(i=0;i<m;i++)  scanf("%ld",q+i);
	int sum=(n+m+1)/2;
	int flag=0;
	long k;
	if(*p>*q) flag=1;
	while(sum--)
	{
		if(flag)
		{
		    k=*q++;
		    m--;
			if((!m)||(*q>*p)) flag=0;	
		}
		else 
		{
			k=*p++;
			n--;
			if((!n)||(*p>*q)) flag=1;
		}
	}
	printf("%ld",k);
}
