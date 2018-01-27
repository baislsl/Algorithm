
#include<stdio.h>
#include<string.h>
char b[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char c[13][5]={"999","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int ff(char a[])
{   int i;
	for(i=0;i<13;i++)
			{
				if(strcmp(b[i],a)==0) return i;
			}
		for(i=0;i<13;i++) if(strcmp(c[i],a)==0) return 13*i;
 			if(i==13) return 0;
}

int main()
{
	int n;
	char a[100];
	
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		gets(a);
		if(a[0]>='0'&&a[0]<='9')
		{   int sum=0;
		    int i=0;
		    while(a[i])
		    {
		    	sum=10*sum+(a[i]-'0');
		    	i++;
		    }
			int p1,p2;
			p1=sum%13;
			p2=sum/13;
			if(p1&&p2) printf("%s %s",c[p2],b[p1]);
			else if(p1||p2) printf("%s",p1?b[p1]:c[p2]);
			else printf("tret");
		}
		else 
		{
			int i,k=strlen(a);
			if(k==3) 
		    printf("%d",ff(a));
			else 
			{
				char b[3]={a[0],a[1],a[2]};
				printf("%d",ff(b)+ff(a+4));
			}
			
		}
		if(n) printf("\n");
	}
}
