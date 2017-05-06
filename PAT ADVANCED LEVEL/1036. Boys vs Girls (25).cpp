#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct one
	{
		char name[11],id[11];
		int grade;
		char fm;
	};
	int n,i;
	int min,max;
	int m[100002],f[100002],xm,xf;
	xm=xf=0;
    scanf("%d",&n);
    struct one *p=(struct one*)malloc(n*sizeof(struct one));
    for(i=0;i<n;i++)
    {
    	scanf("%s",(p+i)->name);
    	getchar();
    	scanf("%c %s%d",&(p+i)->fm,(p+i)->id,&(p+i)->grade);
    	if((p+i)->fm=='M') m[xm++]=i;
    	else if((p+i)->fm=='F') f[xf++]=i;
	}
	if(xf)
	{
		max=f[0];
		for(i=1;i<xf;i++)
		{
			if((p+f[i])->grade>(p+max)->grade) 
			{
				max=f[i];
			}
		}
		printf("%s %s\n",(p+max)->name,(p+max)->id);
	}
	else printf("Absent\n");
	
	if(xm)
	{
		min=m[0];
		for(i=1;i<xm;i++)
		{
			if((p+m[i])->grade<(p+min)->grade) 
			{
				min=m[i];
			}
		}
		printf("%s %s\n",(p+min)->name,(p+min)->id);
	}
	else printf("Absent\n");

	if(xf&&xm)
	{
		printf("%d",(p+max)->grade-(p+min)->grade);
	}
	else printf("NA");
}
