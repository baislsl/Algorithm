//
// Created by baislsl on 17-2-4.
//
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *pa, const void *pb){
    return *(int*)pa - *(int*)pb;
}

int main(){
    int a[100000];
    bool flag[100000] = {false};
    for(int i=0;i<100000;i++){
        a[i] = -1;
        flag[i] = false;
    }
    int n,m;
    scanf("%d",&n);
    while(n--){
        int a1,a2;
        scanf("%d%d",&a1,&a2);
        a[a1] = a2;
        a[a2] = a1;
    }
    scanf("%d",&m);
    int *guests = (int *)malloc(m*sizeof(int));
    for(int i=0;i<m;i++){
        scanf("%d",guests + i);
        flag[guests[i]] = true;
    }

    qsort(guests,m,sizeof(int),cmp);

    bool first = true;


    int *result = (int*)malloc(m*sizeof(int));
    int count = 0;
    for(int i=0;i<m;i++){
        if(a[guests[i]] == -1 || flag[a[guests[i]]] == false){
            result[count++] = guests[i];
        }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d",result[i]);
        if(i!=count - 1) putchar(' ');
    }
}
