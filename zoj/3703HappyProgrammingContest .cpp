#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct one{
    int attac;
    int time;
    int num;

}dp[55][2002];

struct bag{
    int attac;
    int time;
};

int cmp(struct one *a, struct one *b){
    if(a->attac != b->attac)
        return a->attac - b->attac;
    else if(a->num != b->num)
        return a->num - b->num;
    else return b->time - a->time;
}

int bagCmp(const void *pa, const void *pb){
    return ((bag*)pa)->time - ((bag*)pb)->time;
}

int main(){
    int repeat;
    cin >> repeat;
    while(repeat--){
        int T, n;
        cin >> T >> n;
        struct bag bg[55];
        for(int i=0;i<n;i++){
            cin >> bg[i].time;
        }
        for(int i=0;i<n;i++){
            cin >> bg[i].attac;
        }
        qsort(bg, n, sizeof(struct bag), bagCmp);

        for(int index = 0;index <= n; index++)
            for(int j=0;j<=T;j++)
                dp[index][j].attac = dp[index][j].time = dp[index][j].num = 0;

        for(int index = 1;index <= n;index++){

            for(int i=0;i<=T;i++){ //dp[index-1][i-bg[index].time] -> dp[index][i]
                dp[index][i]=dp[index-1][i];///important !!!!!!!
                int j = i - bg[index - 1].time;
                if(j < 0) continue;

                struct one nn;
                nn.attac = dp[index - 1][j].attac + bg[index - 1].attac;
                nn.time = dp[index - 1][j].time + i;
                nn.num = dp[index - 1][j].num + 1 ;
                if(cmp(&(dp[index][i]), &nn) < 0){
                    dp[index][i] = nn;
                }
            }

        }

        struct one *ans = &(dp[0][T]);
        for(int i=0;i<=T;i++){
            for(int j=0;j<=n;j++)
            if(cmp(&(dp[j][i]), ans) > 0) ans = &(dp[j][i]);
        }
        printf("%d %d %d\n", ans->attac, ans->num, ans->time);
    }
}