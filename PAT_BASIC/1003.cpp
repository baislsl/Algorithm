
#include<stdio.h>
int gg(char *p)
{
	int a,b,c,n;
	char cc;
	int flag;
	   a=b=c=0;
	    flag=0;
		while((cc=*p++)!=0)
		{
			if(cc=='A') a++;
			else if(cc=='P') break;
			else 
			{
				flag=1;
				break;
			}
		}
		if(cc!=0)
		while((cc=*p++)!=0)
		{
			if(cc=='A') b++;
			else if(cc=='T') break;
			else 
			{
				flag=1;
				break;
			}
		}
		if(cc!=0)
		while((cc=*p++)!=0)
		{
			if(cc=='A') c++;
			else 
			{
				flag=1;
			}
		}
		
		if((!b)||(a>0&&c!=a*b)) flag=1;
		return flag;
	
}
int main()
{
	char b[101];
	int flag[3],ff;
	int count[3];
	int repeat,i,j;
	scanf("%d",&repeat);
	getchar();
	while(repeat--)
	{   i=0;
	    flag[0]=flag[1]=flag[2]=0;
	    count[0]=count[1]=count[2]=0;
		ff=0;
		gets(b);
		while(b[i]!=0)
		{   
			if(b[i]=='P') flag[0]++;
			else if(b[i]=='A') flag[1]++;
			else if(b[i]=='T') flag[2]++;
			else  
			{
				flag[0]=0;break;
			}
	        if(flag[2]>flag[0]) break;
			i++;
		}
		if((flag[0]==1)&&flag[1]&&(flag[2]==1))
		{
			i=0;j=0;
			while(b[i]!=0) 
			{
				if(b[i]=='P') j++;
				else if(b[i]=='A') count[j]++;
				else if(b[i]=='T') j++;
				i++;
			}
			if((count[0]==0)&&(count[2]==0)&&count[1])  ff=1;
			else if(count[2]-(count[1]-1)*count[0]>0) ff=1;
		}
	    if(ff&&!gg(b)) printf("YES");
	    else printf("NO");
	    if(repeat) printf("\n");
	}
} 