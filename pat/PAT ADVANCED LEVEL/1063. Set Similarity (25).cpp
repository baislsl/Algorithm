#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int compare(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int main()
{
	int sum,n,i,j,k;
	int *p[1002];
	char a[1002];
	memset(a,0,sizeof(char));  //a[i]为0表示p[i]已经排好序 
	scanf("%d",&sum);
	for(i=0;i<sum;i++)
	{
		scanf("%d",&n);
		p[i]=(int *)malloc((n+1)*sizeof(int));
		for(j=0;j<n;j++) scanf("%d",p[i]+j+1);
		*p[i]=n;
	}
	scanf("%d",&sum);
	int nc,nt;
	while(sum--)
	{
		scanf("%d%d",&i,&j);
		i--;j--;
		if(!a[i]) 
		{
			qsort(p[i]+1,*p[i],sizeof(int),compare);
			a[i]=1;
		} 
		if(!a[j])
		{
			qsort(p[j]+1,*p[j],sizeof(int),compare);
		}
		int ix,jx,temp_j;
		ix=jx=nt=0;
		while(ix!=*p[i]+1)
		{
			while(jx<=*p[j]&&*(p[j]+jx)<*(p[i]+ix))
			{
				jx++;
			}
			if(jx<=*p[j]&&*(p[j]+jx)==*(p[i]+ix))
			{
				nt+=2;
				temp_j=jx;
				if(temp_j==jx) nt--;
			}
			int add=0;
			while(*(p[i]+ix)==*(p[j]+jx+1+add)) add++;
			nt+=add; 
			jx--;
			ix++;
		}
		printf("%.1f%%\n",nt*1.0*100/(*p[i]+*p[j]-nt));
	}
	
}






