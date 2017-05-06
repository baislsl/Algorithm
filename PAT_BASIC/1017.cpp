
#include<stdio.h>
#include<string.h>
int m,q;
char a[1100],p[1020];
void find(char *a,int m,int now,int p_x)
{
	if(strlen(a)==1)
	{
		now=now*10+a[0]-'0';
		q=now%m;
		p[p_x]=now/m+'0';
	}
	else
	{
		now=now*10+a[0]-'0';
     	if(now/m!=0||p_x!=0)
     	{
     		p[p_x++]=now/m+'0';
     	}
		now%=m;
		find(a+1,m,now,p_x);
	}
}
int main()
{
	scanf("%s%d",a,&m);
	for(int i=0;i<1020;i++) 
	{
		p[i]=0;
	}
	int now=0;
	find(a,m,now,0);
	printf("%s %d",p,q);
} 