#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define INT_MAX 2147483647
int n, m, pIndex, qIndex;
struct Path {
  int city1, city2;
  int cost;
}*p,*q;  //q is the path in use, and p is the path destroyed

/*used in qsort, sort according to the cost to repair the path*/
int compare(const void *pa, const void *pb) {
  struct Path *a = (struct Path*)pa, *b = (struct Path*)pb;
  return a->cost - b->cost;
}

int find(int i, int *root) {
  if (root[i] == 0) return i;
  else return root[i] = find(root[i],root);
}

/*combine function will combine two city into a city sets, if these two city are already in the same set, return 1, else return 0*/
int combine(int i, int j, int *root) {
  int iRoot = find(i, root), jRoot = find(j, root);
  if (iRoot != jRoot) {
    root[iRoot] = jRoot;
    return 0;
  }
  else return 1;
}

/*return the min cost if one of the citys is destroyed*/
int destroyCity(int destroy) {
  static int root[502];
  int i, cost = 0, count = 0;        //count is the times we connnected two seperated city sets
  for (i = 1; i <= n; i++) root[i] = 0;  //clear the condition of connection between city

  /*add all the path in use to the connected graph*/
  for (i = 0; i < qIndex; i++) {
    int city1 = (q + i)->city1, city2 = (q + i)->city2;
    if (city1 != destroy&&city2 != destroy) {
      if (combine(city1, city2, root) == 0) {
        if (++count == n - 2) return 0;  //count == n - 2 means all the citys are connected now
      }

    }
  }

  /*add the destroyed path into the graph until they are all connected*/
  for (i = 0; i < pIndex; i++) {
    int city1 = (p + i)->city1, city2 = (p + i)->city2;
    if (city1 != destroy&&city2 != destroy) {
      if (combine(city1, city2, root) == 0) {
        cost += (p + i)->cost;
        if (++count == n - 2) break; //count == n - 2 means all the citys are connected now
      }

    }
  }

  if (count == n - 2) return cost;//count == n - 2 represant the graph can be connected using the existing path
  else return INT_MAX;  //if count is no equal to n - 2,it means the graph can not be all connected using all the path.Thus the cost is biggest
}
int main() {
  /*input*/
  scanf("%d%d", &n, &m);
  int i, j, cost, flag;
  p = (struct Path*)malloc(m * sizeof(struct Path));
  q = (struct Path*)malloc(m * sizeof(struct Path));
  while (m--) {
    scanf("%d%d%d%d", &i, &j, &cost, &flag);
    if (flag == 1) {  //the path in use
      (q + qIndex)->city1 = i; (q + qIndex)->city2 = j;
      (q + qIndex)->cost = cost;
      qIndex++;
    }
    else {        //the path destroyed
      (p + pIndex)->city1 = i; (p + pIndex)->city2 = j;
      (p + pIndex)->cost = cost;
      pIndex++;
    }
  }
  /*end input*/

  qsort(p, pIndex, sizeof(struct Path), compare);
  int result[500], resultIndex = 0, max = 0;
  for (i = 1; i <= n; i++) {
    int totalCost = destroyCity(i);
    if (totalCost > max) {
      max = totalCost;
      resultIndex = 0;
      result[resultIndex++] = i;
    }
    else if (totalCost == max && max!=0) {
      result[resultIndex++] = i;
    }
  }

  /*output*/
  if (resultIndex == 0) {  //no need to repair any highway 
    printf("0");
  }
  else {
    printf("%d", result[0]);
      for (i = 1; i < resultIndex; i++) {
        printf(" %d", result[i]);
      }
  }
  /*end output*/
  //system("pause");
}
