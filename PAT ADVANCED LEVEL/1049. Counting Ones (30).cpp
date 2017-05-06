#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int a[14];
int find(char *n,int ind)
{
	if(ind==1) 
	{
		if(n[0]=='0')  return 0;
		else return 1;
	}
    
	if(n[0]=='1') return a[ind-1]+find(n+1,ind-1)+atoi(n+1)+1;
	else if(n[0]=='0') return find(n+1,ind-1);
	else  return pow(10,ind-1)+(n[0]-'0')*a[ind-1]+find(n+1,ind-1);
}
int main()
{
	int i;
	for(i=0;i<14;i++)
	{
		a[i]=i*pow(10,i-1);/*此处a[i]表示从1到pow（10，i-1）总“1”的个数,这结果由附加的代码可求*/ 
	}
    char n[14];
    gets(n);
    printf("%d",find(n,strlen(n)));
}

/*#include<stdio.h>
#include<math.h>
int main()
{
	char a[1000000];
	a[0]=0;
	a[1]=1;
	int i,j,n,m;
	for(i=2;i<10;i++) a[i]=0;
	//scanf("%d",&n);
    int k;
    for(k=1;k<10;k++)
    {
	   n=pow(10,k)-1;
	int ind=0;
	m=n;
	while(m)
	{
		m/=10;
		ind++;
	}
	int sum=0,pow1,pow2=1,mid;
	for(j=1;j<ind;j++)
	{
		pow1=pow2;
		pow2=pow(10,j);
		mid=pow(10,j/2);
		if(j<=6)
		for(i=pow1;i<pow2;i++) 
		{
			*(a+i)=*(a+i/mid)+*(a+i%mid);
			sum+=*(a+i);
		}
		else
		{
			for(i=pow1;i<pow2;i++) sum+=*(a+i/mid)+*(a+i%mid);
		}
	}
	for(i=pow2;i<=n;i++)
	{
		mid=pow(10,ind/2);
		sum+=*(a+i/mid)+*(a+i%mid);
	}
	printf("%d  %d\n",n,sum);
}
}
*/ 
