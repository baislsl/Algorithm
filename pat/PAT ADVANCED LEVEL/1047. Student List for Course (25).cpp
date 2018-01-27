/*这种代码我过一星期后看半小时都不一定看得懂*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *std_count;
struct stu
{
	char name[5];
	int rank;
} *p;
int compare1(const void *a,const void *b)
{
	return strcmp((char *)a,(char *)b);
}
int compare2(const void *a,const void *b)
{
	return std_count[*(int *)a]-std_count[*(int *)b];
}
int main()
{
	int std_num,cla_num;
	scanf("%d%d",&std_num,&cla_num);
	p=(struct stu*)malloc(std_num*sizeof(struct stu));
	int *cla=(int *)malloc(std_num*cla_num*sizeof(int));
	int i,j,k,t;
	int *cla_count=(int *)malloc(cla_num*sizeof(int));
	std_count=(int *)malloc(std_num*sizeof(int));
	for(i=0;i<cla_num;i++) *(cla_count+i)=0;
	for(i=0;i<std_num;i++)
	{
		scanf("%s",(p+i)->name);
		(p+i)->rank=i;
        scanf("%d",&j);
        while(j--)
        {
        	scanf("%d",&k);
        	k--;
        	*( cla + k*std_num + *(cla_count+k) )=i;
        	cla_count[k]++;
		}
	}
	qsort(p,std_num,sizeof(struct stu),compare1);
	for(i=0;i<std_num;i++)
	{
		*(std_count+(p+i)->rank)=i;
	}
	for(i=0;i<cla_num;i++)
	{
		printf("%d %d\n",i+1,*(cla_count+i));
		qsort(cla+i*std_num,*(cla_count+i),sizeof(int),compare2);
		for(j=0;j<cla_count[i];j++)
		{
			puts((p+*(std_count+*(cla+i*std_num+j)))->name);
		}
	}
} 
