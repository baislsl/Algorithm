
#include<stdio.h>
int main()
{
	static int b[29];
	char cc;
	while((cc=getchar())!='\n')
	{
		if(cc>='a'&&cc<='z') b[cc-'a']++;
		else if(cc>='A'&&cc<='Z') b[cc-'A']++;
	}
	int max=0,i;
	for(i=1;i<=28;i++)
	{
		if(b[i]>b[max]) max=i;
	}
	printf("%c %d",max+'a',b[max]);
}