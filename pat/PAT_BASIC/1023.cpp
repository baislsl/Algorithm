
#include<stdio.h>
int main()
{
	int a[10],i,j,k;
	for(i=0;i<10;i++) 
	{
		scanf("%d",a+i);
	}
	i=1;
	while(a[i]==0) i++;
	printf("%d",i);
	a[i]--;
	for(i=0;i<10;i++)
	{
		if(a[i]==0) continue;
		else 
		{
			for(k=0;k<a[i];k++) printf("%d",i);
		}
	}
}