#include<stdio.h>
char n[4];
int my_int1(char *a)
{
	int n,i,flag;
	do
	{
		flag=0;
		char cc;
	   for(i=1;i<4;i++)
	   {
	   	  if(a[i]>a[i-1])
	   	  {
	   	  	cc=a[i];
	   	  	a[i]=a[i-1];
	   	  	a[i-1]=cc;
	   	  	flag=1;
	   	  }
	   }
    }while(flag);
    return (a[3]-'0')*1000+(a[2]-'0')*100+(a[1]-'0')*10+a[0]-'0';
}
int my_int2(char *a)
{
		int n,i,flag;
	do
	{
		flag=0;
		char cc;
	   for(i=1;i<4;i++)
	   {
	   	  if(a[i]<a[i-1])
	   	  {
	   	  	cc=a[i];
	   	  	a[i]=a[i-1];
	   	  	a[i-1]=cc;
	   	  	flag=1;
	   	  }
	   }
    }while(flag);
    return (a[3]-'0')*1000+(a[2]-'0')*100+(a[1]-'0')*10+a[0]-'0';
}
void my_char(int k)
{
	n[0]=k/1000+'0';
	n[1]=k/100%10+'0';
	n[2]=k/10%10+'0';
	n[3]=k%10+'0';
}
int main()
{
	int na,ma;
	gets(n);
	do
	{
		na=my_int1(n);
		ma=my_int2(n);
		if(ma>na)
		{
		    printf("%04d - %04d = %04d\n",ma,na,ma-na);
		    na=ma-na;
		}
		else
		{
			printf("%04d - %04d = %04d\n",na,ma,na-ma);
			na-=ma;
		}
		my_char(na);
	}while(na!=6174&&na!=0);
} 
