
#include<stdio.h>
int main(){
long int a,b,c;
	int d;
    scanf("%ld%ld%d",&a,&b,&d);
    c=a+b;
    void ff(long c,int d);
    ff(c,d);
}
void ff(long c,int d){
	if(c>=d)  ff(c/d,d);
	printf("%d",c%d);
}