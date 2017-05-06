
#include<stdio.h>
int main()
{
	int da,db;
	long a,b;
	int  shu(long a,int da);
	long kk(int da,int count);
	scanf("%ld%d%ld%d",&a,&da,&b,&db);
    printf("%ld",kk(da,shu(a,da))+kk(db,shu(b,db)));
} 
int shu(long a,int da){
	int count=0;
	do{
		if(a%10==da) count++;
		a/=10;
	}while(a);
	return count;
}
long kk(int da,int count){
	long sum=0;
	int i;
	for(i=1;i<=count;i++){
		sum=10*sum+da;
	}
	return sum;
}