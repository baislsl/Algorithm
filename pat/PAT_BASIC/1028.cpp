
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int sum;
	scanf("%d",&sum);
	getchar();
	int count=0,min,max,i=0,flag=1,first=0;
	min=max=0;
	struct peo
	{
		char a[8];
		int year;
		int day;
		int mon;
		long int total;
	};
	struct peo *p=(struct peo *)malloc(sum*sizeof(struct peo));
	
	while(sum--)
	{   
		scanf("%s %d/%d/%d",(p+i)->a,&(p+i)->year,&(p+i)->mon,&(p+i)->day);
		getchar();
		flag=1;
		if((p+i)->year>2014||((p+i)->year==2014&&(p+i)->mon>9)||((p+i)->year==2014&&(p+i)->mon==9&&(p+i)->day>6))  flag=0;
		else if((p+i)->year<1814||((p+i)->year==1814&&(p+i)->mon<9)||((p+i)->year==1814&&(p+i)->mon==9&&(p+i)->day<6)) flag=0;
		if(flag) 
		{   count++;
			if(!(first++)) min=max=i;
			(p+i)->total=(p+i)->year*10000+(p+i)->mon*100+(p+i)->day;
			if((p+i)->total>(p+max)->total) max=i;
			else if((p+i)->total<(p+min)->total) min=i;
		}
		i++;
	}
	if(count)
	printf("%d %s %s",count,(p+min)->a,(p+max)->a);
	else printf("0");
} 