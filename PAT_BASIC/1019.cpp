
#include<stdio.h>
#include<stdlib.h>
int max,min;
int main()
{
	int n,k;
	scanf("%d",&n);
	void dx(int n);
	if(n%1111==0) {
	printf("%d - %d = 0000",n,n);
	exit(0);}
	if(n==6174){
		printf("7641 - 1467 = 6174");
	}
	while(n!=6174){
		dx(n);
		n=max-min;
	}
}
void dx(int n){
	int a[5];
	int i,j,p;
	char m[5],n1[5],j1[5];
	for(i=1;i<=4;i++){
		a[i]=n%10;
		n/=10;
		m[i-1]=n1[i-1]=j1[i-1]='0';
	}
	n1[4]=m[4]=j1[4]='\0';
	int count=1;
	while(count){
		count=0;
		for(i=1;i<=3;i++)
		   {
		   	if(a[i]<a[i+1]){
		   	      a[i]^=a[i+1]^=a[i]^=a[i+1];
		   	      count ++;}
		   }
	}
	max=min=0;
	for(i=1;i<=4;i++){
		max=10*max+a[i];
		m[4-i]=a[i]+'0';
		n1[i-1]=a[i]+'0';
		min=10*min+a[5-i];
	}
	p=max-min;
    for(i=1;i<=4;i++){
    	j1[4-i]=p%10+'0';
    	p/=10;
    }
	printf("%s - %s = %s\n",n1,m,j1);
}