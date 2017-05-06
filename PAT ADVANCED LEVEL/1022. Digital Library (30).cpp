#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct one
{
	int id;
	char title[81];
	char author[81];
	char key[100][11];
	char pub[81];
	char year[5];
	int keylong;
};
int compare(const void *pa,const void *pb)
{
	struct one *a=(struct one *)pa;
	struct one *b=(struct one *)pb;
	if(a->id>b->id) return 1;
	else if(a->id==b->id) return 0;
	else return -1;
}
int main()
{
	int n,i,j,k;
	char cc;
	scanf("%d",&n);
	struct one *p=(struct one*)malloc(n*sizeof(struct one));
	for(i=0;i<n;i++)
	{
		scanf("%d",&(p+i)->id);
		getchar();
	    gets((p+i)->title);
	    gets((p+i)->author);
		j=k=0;
		while((cc=getchar())!='\n')
		{
			if(cc==' ') 
			{
				(p+i)->key[j][k]=0;
				j++;
				k=0;
			}
			else (p+i)->key[j][k++]=cc;
		}
		(p+i)->keylong=j+1;
		(p+i)->key[j][k]=0;
		gets((p+i)->pub);
        gets((p+i)->year);
	}
	qsort(p,n,sizeof(struct one),compare);
	char find[100];
	int m,flag;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&j);
		getchar();getchar();
		gets(find);
		switch(j)
		{
			case 1:flag=0;
			    printf("1: %s\n",find);
				for(k=0;k<n;k++)
				{
					if(strcmp(find,(p+k)->title)==0)
					{
						printf("%d\n",(p+k)->id);
						flag=1;
					}
			   }
				if(flag) flag=0;
				else printf("Not Found\n");
				break;
			case 2:flag=0;
			    printf("2: %s\n",find);
				for(k=0;k<n;k++)
				{
					if(strcmp(find,(p+k)->author)==0)
					{
						printf("%d\n",(p+k)->id);
						flag=1;
					} 
			    }
				if(flag) flag=0;
				else printf("Not Found\n");
				break;
			case 3:flag=0;
			    printf("3: %s\n",find);
				for(k=0;k<n;k++)
				{
					int g;
					for(g=0;g<(p+k)->keylong;g++)
					{
					    if(strcmp(find,(p+k)->key[g])==0)
					   {
					    	printf("%d\n",(p+k)->id);
						    flag=1;
						    break;
					   } 
				   }
			    }
				if(flag) flag=0;
				else printf("Not Found\n");
				break;
			case 4:flag=0;
			    printf("4: %s\n",find);
				for(k=0;k<n;k++)
				{
					if(strcmp(find,(p+k)->pub)==0)
					{
						printf("%d\n",(p+k)->id);
						flag=1;
					} 
			    }
				if(flag) flag=0;
				else printf("Not Found\n");
				break;
			case 5:flag=0;
			    printf("5: %s\n",find);
				for(k=0;k<n;k++)
				{
					if(strcmp(find,(p+k)->year)==0)
					{
						printf("%d\n",(p+k)->id);
						flag=1;
					} 
			    }
				if(flag) flag=0;
				else printf("Not Found\n");
				break;
		}
	}
}





