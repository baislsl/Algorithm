
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int day,i,j,sum,sum_x;
	double max;
	int may,must;
				may=must=0;

	scanf("%d%lf%d",&sum,&max,&day);
	for(sum_x=0;sum_x<sum;sum_x++)
	{
		double use;
		int total;
		int count=0;
		scanf("%d",&total);
		for(i=0;i<total;i++)
		{
			scanf("%lf",&use);
			if(use<max)
			{
				count++;
			 } 
		}
		if(count>total/2)
		{
			if(total>day)
			{
				must++;
			}
			else may++;
		}
	}
	printf("%.1f%% %.1f%%",may*1.0/sum*100,must*1.0/sum*100);
}