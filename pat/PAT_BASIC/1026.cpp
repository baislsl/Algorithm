
#include<stdio.h>
int main()
{
	long long int begin,last1;
	scanf("%ld%ld",&begin,&last1);
	last1-=begin;
	int last=(int)((double)(last1)/100+0.5);
	int hour,min,sec;
	hour=last/3600;
	last%=3600;
	min=last/60;
	sec=last%60;
	if(hour==0) printf("00:");
	else if(hour<10) printf("0%d:",hour);
	else printf("%d:",hour);
	
	if(min==0) printf("00:");
	else if(min<10) printf("0%d:",min);
	else printf("%d:",min);
	
	if(sec<10) printf("0%d",sec);
	else printf("%d",sec);
}