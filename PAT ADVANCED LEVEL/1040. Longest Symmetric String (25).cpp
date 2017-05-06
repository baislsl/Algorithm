#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char *a=(char *)malloc(1002*sizeof(char));
	a++;
	gets(a);
	*(a-1)='\n';
	int max=0,m,i;
	int left,right;
	for(i=0;a[i];i++)
	{
		left=right=i;
		while(a[left]==a[right])
		{
			left--;right++;
		}
		m=right-left-1;
		if(m>max) max=m;
	}
	for(i=0;a[i+1];i++)
	{
		if(a[i]==a[i+1]) {
			left=i;right=i+1;
			while(a[left]==a[right])
			{
				left--;right++;
			}
			m=right-left-1;
			if(m>max) max=m;
		}
	}
	printf("%d",max);
	
}
