
#include<stdio.h>
int main()
{
  int n,i,j,max=0,flag=1;
  int a[1000],b[6];
  scanf("%d",&n);
  b[1]=b[2]=b[3]=b[4]=b[5]=0;
  for(i=0;i<n;i++)
  {
  	scanf("%d",&a[i]);
  }	
   int a1,a2,a3,a4,a5;
   double A4;
   a1=a2=a3=a4=a5=0;
   j=0;
   for(i=0;i<n;i++){
   	  switch(a[i]%5){
   	  	 case 0:if(a[i]%2==0) a1+=a[i],b[1]++;break;
	     case 1:a2+=flag*a[i];flag=-flag;b[2]++;break;
	     case 2:a3++;b[3]++;break;
        case 3:	a4+=a[i];j++;b[4]++;break;
		   case 4:if(max<a[i])max=a[i];b[5]++;break;
   	  }
   }
   A4=a4*1.0/j;
   if(b[1]==0) printf("N");
   else printf("%d",a1);
   
   	if(b[2]==0) printf(" N");
   	else printf(" %d",a2);
   	if(b[3]==0) printf(" N");
   	else printf(" %d",a3);
   
   if(b[4]==0) printf(" N");
   else printf(" %.1f",A4);
   if(b[5]==0) printf(" N");
   else printf(" %d",max);
   
}