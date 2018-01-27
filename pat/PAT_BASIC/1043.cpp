
#include<stdio.h>
int main()
{
	int b[6]={0,0,0,0,0,0};
	char cc;
	while((cc=getchar())!='\n')
	{
		switch (cc)
		{
			case 'P':b[0]++;break;
			case 'A':b[1]++;break;
			case 'T':b[2]++;break;
			case 'e':b[3]++;break;
			case 's':b[4]++;break;
			case 't':b[5]++;break;
		}
	}
	int flag=1;
	while(flag)
	{
		flag=0;
		if(b[0]) 
		{
			putchar('P');
			b[0]--;
			flag=1;
		}
		if(b[1])
		{
			putchar('A');
			b[1]--;
			flag=1;
		}
		if(b[2])
		{
			putchar('T');
			b[2]--;
			flag=1;
		}
		if(b[3])
		{
			putchar('e');
			flag=1;
			b[3]--;
		}
		if(b[4])
		{
			putchar('s');
			flag=1;
			b[4]--;
		}
		if(b[5])
		{
			putchar('t');
			flag=1;
			b[5]--;
		}
	}
}