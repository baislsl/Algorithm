
#include<stdio.h>
int main(void)
{
    int a[10000],b[10000];
    int i,j,k;
    int n,m;
    char p='0';
    i=j=1;k=0;
    do{
    if(k%2==0) scanf("%d",&b[i++]);
    if(k%2==1) scanf("%d",&a[j++]);
    k++;
}while((p=getchar())!='\n');

    a[j]=a[j+1]=0;
    for(m=1;m<i;m++)
    {b[m]=b[m]*a[m];
    a[m]-=1;
    if(a[m]<0)a[m]=0;
    

printf("%d %d",b[m],a[m]);
if (a[m+1]==0) break;
else printf(" ");
}
}