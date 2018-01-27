
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
	char a[82],b[82],c[82];
	int mm;
	for(mm=0;mm<82;mm++) c[mm]=0;
	gets(a);gets(b);
	
	char aa,bb;
	int i,j;
	i=j=0;
	while(bb=a[i++])
	{
		if(searc(bb,b)&&searc(bb,c)) 
		{
			if(bb>='a'&&bb<='z') bb=bb-'a'+'A';
			c[j++]=bb;
		}
	}
	puts(c);
} 