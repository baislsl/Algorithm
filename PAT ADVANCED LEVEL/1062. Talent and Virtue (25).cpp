#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,l,h;
struct one{
  int name;
  int de,cai,sum;
};
int compare(const void *a,const void *b)
{   
  struct one q=*(struct one*)b;
  struct one qq=*(struct one*)a;
  int n,m;
  if(qq.de>=h&&qq.cai>=h) n=1;
  else if(qq.de>=h) n=2;
  else if(qq.de>=qq.cai) n=3;
  else n=4;
  if(q.de>=h&&q.cai>=h) m=1;
  else if(q.de>=h) m=2;
  else if(q.de>=q.cai) m=3;
  else m=4;
  if(n-m) return n-m;
  else 
  {
    if(qq.sum-q.sum) return q.sum-qq.sum;
    else 
    {
      if(qq.de-q.de) return q.de-qq.de;
      else return qq.name-q.name;
    }
    
  }  
}
int main()
{
  scanf("%d %d %d",&n,&l,&h);
  int i,j,m=0;
  struct one *p=(struct one*)malloc(n*sizeof(struct one));
  for(i=0;m<n;m++)
  {
      scanf("%d%d%d",&(p+i)->name,&(p+i)->de,&(p+i)->cai);
      (p+i)->sum=(p+i)->de+(p+i)->cai;
      if((p+i)->de>=l&&(p+i)->cai>=l) i++;
  }
  qsort(p,i,sizeof(struct one),compare);
  printf("%d\n",i);
  for(j=0;j<i;j++)
  {
    printf("%d %d %d",(p+j)->name,(p+j)->de,(p+j)->cai);
    if(j!=i-1) putchar('\n');
  }
}
