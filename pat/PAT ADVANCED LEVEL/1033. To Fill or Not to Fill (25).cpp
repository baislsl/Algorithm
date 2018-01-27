#include<stdio.h>
#include<stdlib.h>
struct station
{
	double price;
	double distance;
};
int compare(const void *pa,const void *pb)
{
	return (int)(((struct station*)pa)->distance)-(int)(((struct station*)pb)->distance);
}
int main()
{
	double c,total_long,effic,sum=0;
	int n;
	scanf("%lf%lf%lf%d",&c,&total_long,&effic,&n);
	double m600=c*effic;
	struct station *p=(struct station*)malloc((n+1)*sizeof(struct station));
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%lf",&(p+i)->price);
		scanf("%lf",&(p+i)->distance);
	}
	(p+n)->distance=total_long;
	qsort(p,n,sizeof(struct station),compare);
	if(p->distance>0.00001) 
	{
	printf("The maximum travel distance = 0.00");
	exit(0);
    }
    i=0;
    int j,flag=0;
    while(i!=n)
    {
    	if((p+i+1)->distance-(p+i)->distance>m600+0.0001) 
    	{
    		flag=1;
    		break;
		}
		j=i+1;
		while(j!=n)
		{
			if((p+j)->price>(p+i)->price+0.0001) 
			{
			    j++;
			    if((p+j)->distance-(p+i)->distance>m600+0.0001)
			    {
			    	j--;
				    sum-=((p+j)->price-(p+i)->price)*(m600-(p+j)->distance+(p+i)->distance)/effic;
					break;
			    }
		    }
			else break;
		}
		sum+=(p+i)->price/effic*((p+j)->distance-(p+i)->distance);
		//printf("%d->%d\n",i,j);
		i=j;
	}
	if(flag) printf("The maximum travel distance = %.2f",(p+i)->distance+m600);
	else printf("%.2f",sum);
}






