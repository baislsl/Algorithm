#include<stdio.h>
#include<string.h>
char *turn(char a[])
{
	int i=0,j=strlen(a)-1;
	char cc;
	for(;i<j;i++,j--)
	{
		cc=a[i];
		a[i]=a[j];
		a[j]=cc;
	}
	return a;
}
int is(char a[])
{
	int i=0,j=strlen(a)-1;
	int flag=1;
	for(;i<j;i++,j--)
     {
     	if(a[i]!=a[j])
     	{
     		flag=0;
     		break;
     	}
     }
     return flag;
}
int main()
{
	int temp,step;
	static char a[111];
	int b[111];
	scanf("%s",a);
	scanf("%d",&step);
	int ri,i,ff=1;
	for(ri=1;ri<=step;ri++)
	{
		if(ff&&is(a))
		{
			printf("%s\n0",a);
			break;
		}
		else
		{
			ff=0;
			int j=strlen(a),flag=1;
			for(i=0;i<j;i++)
			{
				b[i]=a[i]-'0'+a[j-i-1]-'0';
			}
			b[j]=0;
			for(i=0;i<j;i++)
			{
				if(b[i]>=10)
				{
					flag=0;
				    a[i]=b[i]+'0'-10;
					b[i+1]+=1;
				}
				else a[i]=b[i]+'0';
				if(b[j]) a[j]='1';
			}
			if(flag) {
				printf("%s\n%d",a,ri);
				break;
			}
		}
	}
	
	if(ri>step) printf("%s\n%d",turn(a),step);
} 



