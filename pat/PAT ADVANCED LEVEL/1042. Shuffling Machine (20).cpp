#include<stdio.h>
char a[4];
char *find(int x)
{
	if(x==53) return "J1";
	else if(x==54) return "J2";
	switch((x-1)/13)
	{
		case 0:a[0]='S';break;
		case 1:a[0]='H';break;
		case 2:a[0]='C';break;
		case 3:a[0]='D';break;
	}
	x%=13;
	if(x>=10) 
	{
		a[1]='1';
		a[2]=x-10+'0';
		a[3]=0;
	}
	else if(x==0)
	{
		a[1]='1';
		a[2]='3';
		a[3]=0;
	}
	else
	{
		a[1]=x+'0';
		a[2]=0;
	}
	return a;
}
int main()
{
	int a[55],x[55],y[55];
	int i,repeat,j;
	scanf("%d",&repeat);
	for(i=1;i<=54;i++) 
	{
		scanf("%d",a+i);
		y[i]=i;
	}
	for(i=0;i<repeat;i++)
	{
		if(i%2==0) 
		{
			for(j=1;j<=54;j++)
			   x[a[j]]=y[j];
		}
		else 
		{
			for(j=1;j<=54;j++) 
			    y[a[j]]=x[j];
		}
	}
	if(repeat%2) 
	{
		printf("%s",find(x[1]));
		for(i=2;i<=54;i++) printf(" %s",find(x[i]));
	}
	else{
		printf("%s",find(y[1]));
		for(i=2;i<=54;i++) printf(" %s",find(y[i]));
	}
}
