#include<stdio.h>
#include<stdlib.h>
struct one
{
	int weight,num;//num表示pp指向数字的个数 
	int *pp;
}*p;
int find_w;
int a[100];
int compare(const void *pa,const void *pb)
{
   int *a=(int *)pa;
   int *b=(int *)pb;
	return (p+*b)->weight-(p+*a)->weight;
}
void find(int current_node,int sum_weight,int lon)
{
	int i;
	a[lon++]=(p+current_node)->weight;
	sum_weight+=(p+current_node)->weight;
	if(sum_weight<find_w)
	{
		for(i=0;i<(p+current_node)->num;i++)
		{
			find(*((p+current_node)->pp+i),sum_weight,lon);
		}
	}
	else if(sum_weight==find_w)
	{
		if((p+current_node)->num==0)
		{
			printf("%d",a[0]);
		    for(i=1;i<lon;i++) printf(" %d",a[i]);
		    printf("\n");
		}
	}
}
int main()
{
	int node_num,no_num;
	scanf("%d%d%d",&node_num,&no_num,&find_w);
	int i,j,k;
    p=(struct one*)malloc(node_num*sizeof(struct one));
	for(i=0;i<node_num;i++) 
	{
	    (p+i)->num=0;
	    scanf("%d",&((p+i)->weight));
    } 
	while(no_num--)
	{
		scanf("%d",&i);
		scanf("%d",&((p+i)->num));
		(p+i)->pp=(int *)malloc((p+i)->num*sizeof(int));
		for(j=0;j<(p+i)->num;j++) scanf("%d",(p+i)->pp+j);
		qsort((p+i)->pp,(p+i)->num,sizeof(int),compare);
	}
	find(0,0,0);
}
