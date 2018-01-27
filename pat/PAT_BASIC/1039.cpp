
#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    char b[1000];
    int count,i,j,k;
    gets(b);
    gets(a);
    i=0;
    count=strlen(a);
    while(a[i]){
    	j=0;
    	while(b[j])
    	{
    		if(b[j]==a[i])
    		{
    			count--;
    			b[j]='#';
    			break;
    		}
    	    j++;
    	}
    	if(count) i++;
    	else break;
    }
    if(!count) printf("Yes %d",strlen(b)-strlen(a));
    else printf("No %d",count);
    
}


    
    