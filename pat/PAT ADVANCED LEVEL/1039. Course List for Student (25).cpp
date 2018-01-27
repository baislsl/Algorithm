#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct clas
{
  int num;
  int rank;
  char *pp;
} ;
struct student
{
  char name[5];
  int rank;
  int attend[200];
  int ind;
};
int compare1(const void *pa,const void *pb)
{
  return strncmp((char *)pa,(char *)pb,5);
}
int compare2(const void *pa,const void *pb)
{
  return strcmp((char*)pa,(char*)pb);
}
int main()
{
  int i,j,k,m;
  int student_num,class_num;
  scanf("%d%d",&student_num,&class_num);
  struct clas *p=(struct clas*)malloc(class_num*sizeof(struct clas));
  for(i=0;i<class_num;i++)
  {
    scanf("%d",&k);
    k--;
    scanf("%d",&(p+k)->num);
    (p+k)->pp=(char *)malloc((p+k)->num*5*sizeof(char));
    for(j=0;j<(p+k)->num;j++)
    {
      scanf("%s",(p+k)->pp+5*j*sizeof(char));
    }
    qsort((p+k)->pp,(p+k)->num,5*sizeof(char),compare1);
  }
  int *x=(int *)malloc(class_num*sizeof(int));
  char name[5];
  while(student_num--)
  {
  	j=0;
  	scanf("%s",name);
  	for(i=0;i<class_num;i++)
  	{
  		if(bsearch(name,(p+i)->pp,(p+i)->num,5*sizeof(char),compare2)!=NULL)
  		{
  			x[j++]=i+1;
		}
	}
	printf("%s %d",name,j);
	for(i=0;i<j;i++) printf(" %d",x[i]);
	printf("\n");
  }
}
/*  struct student *std=(struct student *)malloc(student_num*sizeof(struct student));
  for(i=0;i<student_num;i++)
  {
    scanf("%s",(std+i)->name);
    (std+i)->rank=i;
  }
  qsort(std,student_num,sizeof(struct student),compare2);
  for(i=0;i<student_num;i++)
  {
    x[(std+i)->rank]=i;
    (std+i)->ind=0;
  }
  for(i=0;i<class_num;i++)
  {
    k=0;
    for(j=0;j<(p+i)->num;j++)
    {
      for(;k<student_num;k++)
      {
        if(strncmp((std+k)->name,(p+i)->pp+5*j*sizeof(char),5*sizeof(char))==0) 
        {
          (std+k)->attend[(std+k)->ind++]=i+1;
          k++;
          break;
        }
      }
    }
  }
  for(i=0;i<student_num;i++)
  {
    printf("%s %d",(std+x[i])->name,(std+x[i])->ind);
    for(j=0;j<(std+x[i])->ind;j++)
    {
      printf(" %d",(std+x[i])->attend[j]);
    }
    printf("\n");
  }*/

