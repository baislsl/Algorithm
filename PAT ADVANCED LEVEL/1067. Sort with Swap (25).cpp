#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	int *a=(int *)malloc(n*sizeof(int));
	int *b=(int *)malloc(n*sizeof(int));
	int i,temp;
	for(i=0;i<n;i++) 
	{
        scanf("%d",a+i);
        *(b+*(a+i))=i;
	}
	int count = 0;
	i=0;
	while(i!=n)
	{
		if(a[i]!=i)
		{
			count++;
			temp=a[i];
			a[i]=i;
			a[b[i]]=temp;
		}
		i++;
	}
	printf("%d",count);
}
