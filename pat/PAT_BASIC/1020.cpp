
#include<stdio.h>
int main()
{
	int sum,n;
	int i;
	double a[1001][2];
	scanf("%d%d",&n,&sum);
	for(i=0;i<n;i++) scanf("%lf",&a[i][0]);
	for(i=0;i<n;i++) scanf("%lf",&a[i][1]);
	for(i=0;i<n;i++) a[i][1]/=a[i][0];
	
	int index[1001];
	for(i=0;i<n;i++) index[i]=i;
	int count;
	int temp;
	do
	{   count=0;
		for(i=0;i<n-1;i++)
		{
			if(a[index[i]][1]<a[index[i+1]][1]) 
			{
				count=1;
			    temp=index[i];
				index[i]=index[i+1];
				index[i+1]=temp;	
			}
		}
	}while(count);
	
	double money=0;
    for(i=0;i<n;i++)
    {
    	if(sum<=a[index[i]][0]) 
    	{
    		money+=sum*a[index[i]][1];
    		break;
    	}
    	else 
    	{
    		money+=a[index[i]][0]*a[index[i]][1];
    		sum-=a[index[i]][0];
    	}
    }
    
    printf("%.2f",money);
}