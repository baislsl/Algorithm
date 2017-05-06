#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct one
{
	int problem[6];
	int perfect;
	bool flag;
	int sum;
	int name;
}*p;
int a[100000];
int score[6];
int cmp(const void *pb,const void *pa)
{
	struct one *a,*b;
	a=(struct one*)pa; b=(struct one*)pb;
	if(a->sum!=b->sum) return a->sum-b->sum;
	else if(a->perfect!=b->perfect)    return a->perfect-b->perfect;
	else return b->name-a->name;
}
int main()
{
	memset(a,-1,sizeof(a));
	int n,k,m;
	scanf("%d%d%d",&n,&k,&m);
	int i,j;
	p=(struct one*)malloc(n*sizeof(struct one));
	for(i=0;i<k;i++)
	{
		scanf("%d",score+i+1);
	}
	for(i=0;i<n;i++)
	{
		(p+i)->flag=false;
		(p+i)->sum=0;
		(p+i)->perfect=0;
		memset((p+i)->problem,-1,sizeof((p+i)->problem));
	}
	int index=0;
	int string,num,point;
	while(m--)
	{
		scanf("%d%d%d",&string,&num,&point);
		if(a[string]==-1)
		{
			a[string]=index;
			(p+index)->name=string;
			if(point!=-1)
			{
				(p+index)->flag=true;
				if(point==score[num]&&(p+index)->problem[num]!=score[num])
				{
					(p+index)->perfect++;
				}
				if((p+index)->problem[num]<point)
				{
					if((p+index)->problem[num]==-1) (p+index)->sum-=1;
					(p+index)->sum+=point-(p+index)->problem[num];
					(p+index)->problem[num]=point;
				}
			}
			else
			{
				if((p+index)->problem[num]==-1) (p+index)->problem[num]=0;
			}
			index++;
		}
		else
		{
			int temp=index;
			index=a[string];
			if(point!=-1)
			{
				(p+index)->flag=true;
				if(point==score[num]&&(p+index)->problem[num]!=score[num])
				{
					(p+index)->perfect++;
				}
				if((p+index)->problem[num]<point)
				{
					if((p+index)->problem[num]==-1) (p+index)->sum-=1;
					(p+index)->sum+=point-(p+index)->problem[num];
					(p+index)->problem[num]=point;
				}
			}
			else
			{
				if((p+index)->problem[num]==-1) (p+index)->problem[num]=0;
			}
			index=temp;
		}
	}
	qsort(p,index,sizeof(struct one),cmp);
	int last=-1;
	for(i=0;i<index;i++)
	{
		if((p+i)->flag)
		{
			if(i!=0&&((p+i)->sum==(p+i-1)->sum))
			{
				printf("%d ",last);
			}
			else
			{
				last=i+1;
				printf("%d ",i+1);
			}
			printf("%05d %d",(p+i)->name,(p+i)->sum);
			for(int j=1;j<=k;j++)
			{
				if((p+i)->problem[j]==-1) printf(" -");
				else printf(" %d",(p+i)->problem[j]);
			}
			putchar('\n');
		}
	}
}






