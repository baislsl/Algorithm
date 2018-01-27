//
// Created by baislsl on 17-2-4.
//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    bool a[206][206];
    bool flag[206];
    for(int i=0;i<206;i++){
        for(int j=0;j<206;j++)
            a[i][j] = false;
    }


    while(m--){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        a[v1][v2] = a[v2][v1] = true;
    }

    int q[100000];
    scanf("%d",&m);
    while(m--){
        for(int i=0;i<206;i++){
            flag[i] = false;
        }
        int num;
        scanf("%d",&num);
        for(int i=0;i<num;i++){
            scanf("%d",q+i);
        }
        if(num != n+1){
            printf("NO\n");
            continue;
        }else{
            bool result = true;
            for(int i=1;i<=n;i++){
                if(flag[q[i]] == true || a[q[i]][q[i - 1]] == false) {
                    result = false;
                    break;
                }else{
                    flag[q[i]] = true;
                }
            }

            if(result) printf("YES\n");
            else{
                printf("NO\n");
            }
        }
    }
}

