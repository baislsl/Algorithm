#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct one
{
	char name[14];
	int score,local_num,local_rank,final_rank;
};
int compare(const void *pa,const void *pb)
{
	struct one *a=(struct one*)pa;
	struct one *b=(struct one*)pb;
	if(a->score==b->score){
		return strcmp(a->name,b->name);
	}
	else return b->score-a->score;
}
int main()
{
	int sum,local,n,i,j;
	struct one *p[101];
	int b[101];
	sum=0;
	scanf("%d",&local);
	for(i=0;i<local;i++)
	{
		scanf("%d",&n);
		sum+=n;
		b[i]=n;
		p[i]=(struct one*)malloc(n*sizeof(struct one));
		while(n--)
		{
			scanf("%s%d",(p[i]+n)->name,&(p[i]+n)->score);
			(p[i]+n)->local_num=i+1;
		}
		qsort(p[i],b[i],sizeof(struct one),compare);
		for(j=0;j<b[i];j++)
		{
			if(j==0) (p[i]+j)->local_rank=j+1;
			else 
			{
				if((p[i]+j)->score==(p[i]+j-1)->score)
				{
					(p[i]+j)->local_rank=(p[i]+j-1)->local_rank;
				}
				else (p[i]+j)->local_rank=j+1;
			}
		}
	}
	struct one *q=(struct one*)malloc(sum*sizeof(struct one));
	int index=0;
	for(i=0;i<local;i++)
	{
		for(j=0;j<b[i];j++)
		{
			*(q+index++)=*(p[i]+j);
		}
		free(p[i]);
	}
	qsort(q,sum,sizeof(struct one),compare);
	for(i=0;i<sum;i++)
	{
		if(i==0) (q+i)->final_rank=1;
		else 
		{
			if((q+i)->score==(q+i-1)->score) (q+i)->final_rank=(q+i-1)->final_rank;
			else (q+i)->final_rank=i+1;
		}
	}
	printf("%d\n",sum);
	for(i=0;i<sum;i++)
	{
		printf("%s %d %d %d\n",(q+i)->name,(q+i)->final_rank,(q+i)->local_num,(q+i)->local_rank);
	}
	free(q);
}
