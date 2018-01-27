#include<stdio.h>
#include<stdlib.h>
struct one
{
	int wei;
	int top;
	int time;
}*p;
int compare2(const void *pa,const void *pb)
{
	return ((struct one*)pa)->wei-((struct one*)pb)->wei;
}
int main()
{
	int n,group;
	int i,j,k;
	scanf("%d%d",&n,&group);
    p=(struct one *)malloc(n*sizeof(struct one));
    int *x=(int *)malloc(n*sizeof(int));
    int *rank=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++) 
    {
    	scanf("%d",&((p+i)->wei));
    	(p+i)->time=i;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",rank+i);
	}
	int count,num,flag=0,ran;
	ran=-100000;
	i=0;
	count=n;
	while(count!=1)
	{

		num=group;
	    
		while(num--)
		{
			if(i==n) 
			{
				flag=1;
				break;
			}
			
			if((p+rank[i])->wei<0)
			{
				num++;
			}
			else 
			{
				if(num!=group-1)
				{
					count--;
					if((p+rank[i])->wei>(p+rank[j])->wei)
					{
						(p+rank[j])->wei=ran;
						j=i;
					}
					else 
					{
						(p+rank[i])->wei=ran;
					}
				}
				else 
				{
					j=i;
				}
			}
			i++;
		}
		if(flag)
		{
			flag=0;
			ran++;
			i=0;
		}
		
	}
     qsort(p,n,sizeof(struct one),compare2);
     (p+n-1)->top=1;
     for(i=n-2;i>=0;i--) 
     {
     	if((p+i)->wei==(p+i+1)->wei) (p+i)->top=(p+i+1)->top;
        else (p+i)->top=n-i;
	 }
     for(i=0;i<n;i++) x[(p+i)->time]=i;
	 printf("%d",(p+x[0])->top);
	 for(i=1;i<n;i++) printf(" %d",(p+x[i])->top);
}





