#include<stdio.h>
int main()
{
	char array[100002];
	gets(array);
	
	int a[100002][2];
    int i,j=0;
    int b[100002];
    int coup,cout;
    long int sum=0;
    coup=cout=0;
    for(i=0;array[i];i++)
    {
    	if(array[i]=='A') b[j++]=i;
    }
    b[j]=-1;
    for(i=0;b[i]!=-1;i++)
    {
    	for(j=0;j<b[i];j++) if(array[j]=='P') coup++;
    	for(j=b[i];array[j];j++) if(array[j]=='T') cout++;
    	sum+=coup*cout;
        if(sum>1000000007) sum-=1000000007;
    	cout=coup=0;
    }
    printf("%d",sum);
}
