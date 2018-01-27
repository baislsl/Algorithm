#include<stdio.h>
#include<string.h>
void turn(char *a)
{
	int i,j;
	char temp;
	for(i=0,j=strlen(a)-1;i<j;i++,j--)
	{
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	}
}
void add(char *a,char *b,int carry)
{
	if(*a==0&&*b==0)
	{
		if(carry)
		{
			*a='1';
			*(a+1)=0;
		}
	}
	else
	{
		if(*a==0) 
		{
			*a='0';
			*(a+1)=0;
		}
		if(*b==0) 
		{
			*b='0';
			*(b+1)=0;
		}
		*a=*a-'0'+*b+carry;
		if(*a>'9')
		{
			*a-=10;
			add(a+1,b+1,1);
		}
		else
		{
			add(a+1,b+1,0);
		}
		
	}
}
int main()
{
	int repeat,ri;
	char a[30],b[30],c[30],left[30],right[30];
	scanf("%d",&repeat);
	int flag;
	for(ri=1;ri<=repeat;ri++)
	{
		left[0]=right[0]='0';
		left[1]=right[1]=0;
		scanf("%s%s%s",a,b,c);
		printf("Case #%d: ",ri);
		
	    if(a[0]=='-')
	    {
	    	turn(a+1);
	    	add(right,a+1,0);
		}
		else 
		{
			turn(a);
			add(left,a,0);
		}
		if(b[0]=='-')
		{
			turn(b+1);
			add(right,b+1,0);
		}
		else
		{
			turn(b);
			add(left,b,0);
		}
		if(c[0]=='-')
		{
			turn(c+1);
			add(left,c+1,0);
		}
		else
		{
			turn(c);
			add(right,c,0);
	    }
		
	//	puts(left);puts(right);
		if(strlen(left)==strlen(right)) 
		{
			turn(left);
			turn(right);
			flag=strcmp(left,right);
		}
		else
		{
			flag=strlen(left)-strlen(right);
		}
		if(flag>0) printf("true\n");
		else printf("false\n");
	}
} 






