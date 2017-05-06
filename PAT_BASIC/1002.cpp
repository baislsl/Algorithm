
#include<stdio.h>
void ff(int sum);
int main()
{
	char a[102];
	int sum,i=1,j;
	while((a[i]=getchar())!='\n'){i++;
	}
	sum=0;
	for(j=1;j<i;j++){
		sum+=a[j]-'0';
	}
	ff(sum);

}
void ff(int sum)
{    static int k=0; 
	if(sum>=10) {
	 ff(sum/10);}
	if(sum>=10)
	switch(sum%10){
	    case 0:printf(" ling");break;
	    case 1:printf(" yi");break;
	    case 2:printf(" er");break;
	    case 3:printf(" san");break;
	    case 4:printf(" si");break;
	    case 5:printf(" wu");break;
	    case 6:printf(" liu");break;
	    case 7:printf(" qi");break;
	    case 8:printf(" ba");break;
	    case 9:printf(" jiu");break;
	}
	else 
	switch(sum%10){
	    case 0:printf("ling");break;
	    case 1:printf("yi");break;
	    case 2:printf("er");break;
	    case 3:printf("san");break;
	    case 4:printf("si");break;
	    case 5:printf("wu");break;
	    case 6:printf("liu");break;
	    case 7:printf("qi");break;
	    case 8:printf("ba");break;
	    case 9:printf("jiu");break;
	}
	
}