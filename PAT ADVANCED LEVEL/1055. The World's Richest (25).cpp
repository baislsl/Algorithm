#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct one
{
	char name[9];
	int age;
	int money;
}*p;
int compare1(const void *pa,const void *pb)
{
	int a=*(int *)pa,b=*(int *)pb;
	if((p+a)->money!=(p+b)->money) return (p+b)->money-(p+a)->money;
	else 
	{
		if((p+a)->age!=(p+b)->age) return (p+a)->age-(p+b)->age;
		else return strcmp((p+a)->name,(p+b)->name);
	}
}
int compare2(const void *pa,const void *pb)
{
	struct one *a=(struct one *)pa;
	struct one *b=(struct one *)pb;
	if(a->money!=b->money) return b->money-a->money;
	else 
	{
		if(a->age!=b->age) return a->age-b->age;
		else return strcmp(a->name,b->name);
	}
}
int main()
{
	int n,step;
	scanf("%d%d",&n,&step);
	int i,j,k;
	p=(struct one *)malloc(n*sizeof(struct one));
	for(i=0;i<n;i++)
	{
		scanf("%s",(p+i)->name);
		scanf("%d%d",&((p+i)->age),&((p+i)->money));
	}
	int max,min,lon,ax,flag=1,count=1;;
    int *a=(int *)malloc(n*sizeof(int));
	for(j=1;j<=step;j++)
	{
		printf("Case #%d:\n",j);
		ax=0;
		scanf("%d%d%d",&lon,&min,&max);
		if(flag)
		{
			for(i=0;i<n;i++)
		    {
			    if((p+i)->age>=min&&(p+i)->age<=max) 
			    {
				    a[ax++]=i;
		  	    }
		    }
		    if(ax==0) printf("None\n");
		    else 
	 	    {
			    if(ax>n/2) flag=0;
			    qsort(a,ax,sizeof(int),compare1);
			    if(ax>lon) ax=lon;
			    for(i=0;i<ax;i++) printf("%s %d %d\n",(p+a[i])->name,(p+a[i])->age,(p+a[i])->money);
		    }
		}
		else
		{
			if(count) 
			{
				qsort(p,n,sizeof(struct one),compare2);
				count=0;
			}
			for(i=0;i<n;i++)
		    {
			    if((p+i)->age>=min&&(p+i)->age<=max) 
			    {
				    if(++ax<=lon) printf("%s %d %d\n",(p+i)->name,(p+i)->age,(p+i)->money);
				    else break;
			    }
		    }
		    if(ax==0) printf("None\n");
		}
	}
} 
