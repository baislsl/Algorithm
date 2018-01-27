
#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	char a[20];
	char out[100][19];
	int count=0;
	int b[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int sum,i,flag;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(a);
		sum=i=0;
		flag=0;
		for(i=0;i<17;i++)
		{
			if(a[i]<'0'||a[i]>'9') 
			{
				flag=1;
				break;
			}
			else sum+=b[i]*(a[i]-'0');
		}
		sum%=11;
		if(sum==0) 
		{
			if(a[17]!='1') flag=1;
		}
		else if(sum==1) 
		{
			if(a[17]!='0') flag=1;
		}
		else  if(sum==2)
		{
			if(a[17]!='X') flag=1;
		}
		else 
		{
			if(a[17]!=12-sum+'0') flag=1;
		}
		
		if(flag) strcpy(out[count++],a);
	}
	
	if(count) 
	{
		
		for(i=0;i<count;i++) puts(out[i]);
	}
	else printf("All passed");
}