
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,find;
	struct std{
		char lon[15];
		int ji;
		int kao;
	};
	scanf("%d",&n);
	getchar();
	struct std *p=(struct std *)malloc(n*sizeof(struct std));
	int i;
	for(i=0;i<n;i++)
	{   int j;
	    for(j=0;j<=14;j++) (p+i)->lon[j]=getchar();
	    (p+i)->lon[14]=0;
		scanf("%d %d",&((p+i)->ji),&((p+i)->kao));
		getchar();
	}
	
	scanf("%d",&find);
	int t;
	while(find--)
	{
		scanf("%d",&t);
		for(i=0;i<n;i++) 
		{
		   if((p+i)->ji==t)
		   {
			   printf("%s %d",(p+i)->lon,(p+i)->kao);
			   if(find) printf("\n");
			   break;
		   }
		}
	}
} 