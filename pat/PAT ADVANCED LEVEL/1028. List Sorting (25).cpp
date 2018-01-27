#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct one{
	char id[7],name[9];
	int score;
};
int com1(const void *pa,const void *pb)
{
	struct one *a=(struct one*)pa;
	struct one *b=(struct one*)pb;
	return strcmp(a->id,b->id);
}
int com2(const void *pa,const void *pb)
{
	struct one *a=(struct one*)pa;
	struct one *b=(struct one*)pb;
	if(strcmp(a->name,b->name)){
		return strcmp(a->name,b->name);
	}
	else return strcmp(a->id,b->id);
}
int com3(const void *pa,const void *pb)
{
	struct one *a=(struct one*)pa;
	struct one *b=(struct one*)pb;
	if(a->score==b->score) return strcmp(a->id,b->id);
	else return a->score-b->score;
}
int main() 
{
	int n,c;
	scanf("%d%d",&n,&c);
	int i,j;
	struct one *p=(struct one*)malloc(n*sizeof(struct one));
	for(i=0;i<n;i++)
	{
		scanf("%s",(p+i)->id);
		scanf("%s",(p+i)->name);
		scanf("%d",&(p+i)->score);
	}
	switch(c)
	{
		case 1 :qsort(p,n,sizeof(struct one),com1);
		        break;
		case 2 :qsort(p,n,sizeof(struct one),com2);
		        break;
		case 3 :qsort(p,n,sizeof(struct one),com3);
		        break;  
	}
	for(i=0;i<n;i++){
		printf("%s %s %d\n",(p+i)->id,(p+i)->name,(p+i)->score);
	}
	
}
