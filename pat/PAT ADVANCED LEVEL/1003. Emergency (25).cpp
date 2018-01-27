#include<stdio.h>
#include<stdlib.h>
int n,m,now,last,min,max=0,*road;
struct city
{
	int sum_team;
	int *next;
	int *lon;
	int num;
}*p;
void find_short_path(int now,int team,int path)
{
	int i,next;
	if(now!=last)
	{
		for(i=0;i<(p+now)->num;i++)
		{
			next=*((p+now)->next+i);
			if(road[next]==0)
			{
			road[next]=1;
			find_short_path(next,team+(p+now)->sum_team,path+*((p+now)->lon+i));
			road[next]=0;
		    }
		}
	}
	else
	{
		team+=(p+now)->sum_team;
		if(path<min)
		{
			min=path;
			max=team;
		}
		else
		{
			if(path==min)
			{
				if(team>max)
				{
					max=team;
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&now,&last);
	p=(struct city*)malloc(n*sizeof(struct city));
	road=(int *)malloc(n*sizeof(int));
	int i;
	for(i=0;i<n;i++)
	{
		road[i]=0;
		scanf("%d",&(p+i)->sum_team);
		(p+i)->num=0;
		(p+i)->next=(int *)malloc(m*sizeof(int));
		(p+i)->lon =(int *)malloc(m*sizeof(int));
	}
	int a1,a2,path;
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a1,&a2,&path);
		min+=path;
		*((p+a1)->next+(p+a1)->num)=a2;
		*((p+a2)->next+(p+a2)->num)=a1;
		*((p+a1)->lon+(p+a1)->num)=*((p+a2)->lon+(p+a2)->num)=path;
		(p+a1)->num++;(p+a2)->num++;
	}
	road[now]=1;
	find_short_path(now,0,0);
	printf("%d %d",min,max);
} 

