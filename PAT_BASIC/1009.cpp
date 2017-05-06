
# include<stdio.h>
#include<stdlib.h> 
#include<string.h>
int main(void)
{
	int i=0,j,k;
	char a[80];
	char p,*str[80];
	p='0';
	do{
	scanf("%s",a);
    str[i]=(char*) malloc(sizeof(char)*(strlen(a)+1));
    strcpy(str[i],a);
    i++;
	p=getchar();
	  }while(p!='\n');
	for(j=i-1;j>=0;j--)  {
		printf("%s",str[j]);
		if(j!=0) printf(" ");
	}
	
}

