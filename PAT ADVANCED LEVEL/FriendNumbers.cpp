#include <stdlib.h>
#include <stdio.h>

int anly(int k){

    int result = 0;
    while(k){
        result += k%10;
        k/=10;
    }

    return result;
}

int main(){
    int n,count = 0;
    char a[10010] = {0};
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        int ID = anly(k);
        if(a[ID] == 0){
            a[ID] = 1;
            count++;
        }

    }

    printf("%d\n",count);
    for(int i=0;i<10000;i++){
        if(a[i]){
            if(--count == 0){
                printf("%d",i);
            }else{
                printf("%d ",i);
            }
        }
    }
}