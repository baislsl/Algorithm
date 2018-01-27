
#include<stdio.h>
#include<stdlib.h>
int main()
{
	struct std{
		char cj[100];
		char name[100];
		int k;
	};
	int n,i,j,min,max;
	scanf("%d",&n);
    struct std *p=(struct std *) malloc(n*sizeof(struct std));
    for(i=0;i<=n-1;i++)
    {
    	scanf("%s",&(*(p+i)).cj);
    	scanf("%s",&(*(p+i)).name);
    	scanf("%d",&(*(p+i)).k);}
    	min=max=0;
    	for(i=1;i<n;i++){
    		if((*(p+i)).k>(*(p+max)).k) max=i;
    		if((*(p+i)).k<(*(p+min)).k) min=i;
    	}
    printf("%s %s\n",(*(p+max)).cj,(*(p+max)).name);
    printf("%s %s",(*(p+min)).cj,(*(p+min)).name);
}
