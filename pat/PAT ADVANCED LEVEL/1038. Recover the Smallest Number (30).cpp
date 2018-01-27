#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *pa,const void *pb)
{
	char *a=(char*)pa;
	char *b=(char*)pb;
	int long_a=strlen(a),long_b=strlen(b);
	if(long_a==long_b) return strcmp(a,b);
	else 
	{
		if(long_a>long_b) 
		{
			if(strncmp(a,b,long_b)) return strcmp(a,b);
			else return compare((const void*)(a+long_b),(const void*)b);
		}
		else
		{
			if(strncmp(a,b,long_a)) return strcmp(a,b);
			else return compare((const void*)a,(const void*)(b+long_a));
	   }
	}
}
int main()
{
	int i,j,n,flag=0;
	char a[10002][9];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%s",a[i]);
	qsort(a,n,9*sizeof(char),compare);
	char cc;
	i=0;
	while(i!=n)
	{
		j=0;
		cc=a[i][0];
		while(cc=='0') 
		{
		   cc=*(a[i]+(++j));
		   if(cc==0) break;
	    }
		if(cc) 
		{
			flag=1;
			break;
		}
		else 
		{
			i++;
		}
	}
	if(flag)
	{
		while(a[i][j]) putchar(a[i][j++]);
		for(i++;i<n;i++) printf("%s",a[i]);
	}
	else printf("0");
}
