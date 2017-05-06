
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int compare(const void *a,const void *b)
{
	int i=*(int*)a;
	int j=*(int*)b;
	return j-i;
}
void search(int N,int *n,int *m)
{
	double p=sqrt(N);
	int i=p;
	while(N%i) i--;
	*m=N/i;
	*n=i;
}
int main()

{
	int N,M=0;
	int n,m,i,j;
	int x,y;
	x=y=0;
	int a[100][1000];
	scanf("%d",&N);
	int *p=(int *)malloc(N*sizeof(int));
	for(i=0;i<N;i++)
	{
		scanf("%d",p+i);
	}
	
	int coun=0;
/*	do
	{   coun=0;
		for(i=0;i<N-1;i++)
		{
			if(*(p+i)<*(p+i+1))
			{
				coun=1;
				*(p+i)+=*(p+i+1);
				*(p+i+1)=*(p+i)-*(p+i+1);
				*(p+i)-=*(p+i+1);
			}
		}
	}while(coun);*/
	
	qsort(p,N,sizeof(int),compare);
	
	search(N,&n,&m);//寻找合适的n，m 
	
	int two=0,cha=0;
	x=-1;
	int count[4]={0,0,0,0};
     for(i=0;i<N;i++)
     {  
	    
     	switch(M)
     	{
     		case 0:a[++x][y]=*(p+i);
     		       count[M]++;
     		       if(count[M]==n-cha)
     		       {
     		       	two++;
					if(two%2) cha++;
					M=1;count[0]=0;
     		       }
     		       break;
     		       
     		case 1:a[x][++y]=*(p+i);
			       count[M]++;
     		       if(count[M]==m-cha)
     		       {
     		       	two++;
					if(two%2) cha++;
					M=2;count[1]=0;
     		       }
     		       break;
     		       
     		case 2:a[--x][y]=*(p+i);
     		        count[M]++;
     		       if(count[M]==n-cha)
     		       {
     		       	two++;
					if(two%2) cha++;
					M=3;count[2]=0;
     		       }
     		       break;
     		       
     		case 3:a[x][--y]=*(p+i);
     		       count[M]++;
     		       if(count[M]==m-cha)
     		       {
     		       	two++;
					if(two%2) cha++;
					M=0;count[3]=0;
     		       }
     		       break;
     	}
     	
     }
     
     for(y=0;y<m;y++)
     {
     	for(x=0;x<n;x++)
     	{
     		printf("%d",a[x][y]);
     		if(x!=n-1) printf(" ");
     		else putchar('\n');
     	}
     }
}