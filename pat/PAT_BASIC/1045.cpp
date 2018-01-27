
#include<stdio.h>
#include<stdlib.h>
struct one
{
	int num;
	int x;
};
int compare(const void *pa,const void *pb)
{
	struct one *a=(struct one *)pa;
	struct one *b=(struct one *)pb;
	return a->num-b->num;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	struct one *p=(struct one *)malloc(n*sizeof(struct one *));
	for(i=0;i<n;i++)
	{
		scanf("%d",&(p+i)->num);
		(p+i)->x=i;
	}
	qsort(p,n,sizeof(struct one),compare);
	int ind[100005],count=0,j;
	for(i=0;i<n;i++)
	{
		if((p+i)->x==i)
		{
			ind[count++]=i;
		}
		else if((p+i)->x>i)
		{
			int max=(p+i)->x;
			for(j=i+1;j<max;j++)
			{
				if((p+j)->x>max) max=(p+j)->x;
			}
			i=max;
		}
	}
	if(count) printf("%d\n%d",count,(p+ind[0])->num);
	else printf("0\n\n");
	for(i=1;i<count;i++)
	{
		printf(" %d",*(p+ind[i]));
	}
}
