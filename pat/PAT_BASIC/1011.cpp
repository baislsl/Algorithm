
#include<stdio.h>
int main(void)
{
    long long int a,b,c;
    int p[11];
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    scanf("%ld%ld%ld",&a,&b,&c);
    p[i]=   a+b>c ? 1:0;   
       }      
    for(i=1;i<=n;i++)
    {
              if(p[i]==1)        printf("Case #%d: true\n",i);
                else      printf("Case #%d: false\n",i);

}
}