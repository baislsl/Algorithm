
#include<stdio.h>
#include<string.h>
int main()
{
	char num[10005],result[30030],*pr,temp;
	int i,n,flag=1;
	for(i=0;i<30030;i++)
		result[i]='0';
	scanf("%s",num);
	for(i=0;num[i];i++)
	{
		if(num[i]=='E')
		{
			num[i]='\0';
			break;
		}
	}
	sscanf(num+i+1,"%d",&n);
	strcpy(result+10010,num);
	pr=strchr(result,'.');
	if(*(pr-2)=='-')
		flag=-1;
	if(n<=0)
	{
		n=-n;
		while(n>0)
		{
			if(*(pr-1)=='+'||*(pr-1)=='-')
				*(pr-1)='0';
			temp=*(pr-1);
			*(pr-1)=*(pr);
			*(pr)=temp;
			pr--;
			n--;
		}
		pr--;
		if(flag==-1)
			printf("-%s\n",pr);
		else
			printf("%s\n",pr);
	}
	else
	{
		if(n<strlen(pr+1))
		{
			while(n>0)
			{
				temp=*(pr+1);
				*(pr+1)=*pr;
				*pr=temp;
				pr++;
				n--;
			}
		}
		else
		{
			*(pr+strlen(pr))='0';
			while(n>0)
			{
				temp=*(pr+1);
				*(pr+1)=*pr;
				*pr=temp;
				pr++;
				n--;
			}
			*pr='\0';
		}
		if(*(result+10010)=='+')
			printf("%s\n",result+10011);
		else
			printf("%s\n",result+10010);
	}
	return 0;
}