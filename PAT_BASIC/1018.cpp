
#include<stdio.h>
int main() 
{
	static int jia[2][3],yi[2][3];
	char c1,c2;
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		c1=getchar();
		getchar();
		c2=getchar();
		getchar();
		if(c1=='B')
		{
			if(c2=='B') 
			{
				jia[0][1]++;
				yi[0][1]++;
			}
			else if(c2=='C')
			{
				jia[0][0]++;
				jia[1][0]++;
				yi[0][2]++;
			}
			else {
				jia[0][2]++;
				yi[0][0]++;
				yi[1][0]++;
			}
		}
		else if(c1=='C')
		{
			if(c2=='C')
			{
				jia[0][1]++;
				yi[0][1]++;
			}
			else if(c2=='B')
			{
				yi[0][0]++;
				jia[0][2]++;
				yi[1][1]++;
			}
			else 
			{
				jia[0][0]++;
				jia[1][1]++;
				yi[0][2]++;
			}
		}
		else 
		{
			if(c2=='J')
			{
				jia[0][1]++;
				yi[0][1]++;
			}
			else if(c2=='B')
			{
				jia[0][0]++;
				yi[0][2]++;
				jia[1][2]++;
			}
			else
			{
				yi[0][0]++;
				jia[0][2]++;
				yi[1][2]++;
			}
		}
		
	}
	
	printf("%d %d %d\n%d %d %d\n",jia[0][0],jia[0][1],jia[0][2],yi[0][0],yi[0][1],yi[0][2]);
	if(jia[1][0]>=jia[1][1]&&jia[1][0]>=jia[1][2]) putchar('B');
	else if(jia[1][1]>=jia[1][2]) putchar('C');
	else putchar('J');
	printf(" ");
	if(yi[1][1]>=yi[1][2]&&yi[1][1]>=yi[1][0]) putchar('B');
	else if(yi[1][2]>=yi[1][0])  putchar('C');
	else putchar('J');
}