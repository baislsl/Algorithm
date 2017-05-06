
#include<stdio.h>
int main()
{
	 static int pp[1002];
	int a,b,n;
	scanf("%d",&n);
	getchar();int i;
	while(n--)
	{
		scanf("%d-%d %d",&i,&a,&b);
		pp[i]+=b;
	}
	int max;
	max=0;
	for(i=1;i<1002;i++) if(pp[i]>pp[max]) max=i;
	printf("%d %d",max,pp[max]);
}
