
#include<stdio.h>
int searc(char cc,char c[])
{
	int i=0;
	while(c[i]) 
	{
	if(c[i]==cc||('a'<=cc&&cc<='z'&&cc-'a'+'A'==c[i])||('A'<=cc&&cc<='Z'&&cc-'A'+'a'==c[i])) return 0;
	i++;
    }
	return 1;
}
int main()
{
	char a[100003],b[100003],c[100003];
	int mm;
	for(mm=0;mm<100003;mm++) c[mm]=0;
	gets(a);gets(b);
	
	char aa,bb;
	int i,j;
	i=j=0;
	int flag=searc('+',a);
	while(bb=b[i++])
	{   
		if(searc(bb,a)) 
		{
		    if(flag||!(bb>='A'&&bb<='Z'))	
			c[j++]=bb;
		}
		
	}
	puts(c);
} 