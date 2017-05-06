
#include<stdio.h>
#include<string.h>
void swap(char *p)
{
	int i=0,j=strlen(p)-1;
	char cc;
	for(;i<j;i++,j--)
	{
		cc=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=cc;
	}
}
char gg(char a,char b)
{
	int k=a-'0'+b-'0';
	k%=13;
	if(k<10) return k+'0';
	else if(k==10) return 'J';
	else if(k==11) return 'Q';
	else return 'K';
}
char ff(char a,char b)//奇数位 
{
	int k=b-a;
	if(k<0) k+=10;
	return k+'0';
}
int main()
{
	char a[102];
	char b[102];
	int i;
	i=0;
	while((a[i++]=getchar())!=' ');
    a[i-1]=0;
    gets(b);
    int bb;
    int j;
    swap(a);swap(b);
    for(i=strlen(a);i<102;i++) a[i]='0';
    for(bb=j=strlen(b);j<102;j++)  b[j]='0';
    for(i=0;i<102;i++)
    {
    	  if(i%2) b[i]=ff(a[i],b[i]);
    	  else b[i]=gg(a[i],b[i]);
    }
    for(bb=101;bb>=1;bb--) if(b[bb]!='0') break;
    b[bb+1]=0;
    swap(b);
    
    puts(b);
	
}
