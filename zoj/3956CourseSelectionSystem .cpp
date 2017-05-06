#include <bits/stdc++.h>

using namespace std;

struct one{
    int a, b;
    double ca, cb;
    int index;
}p[600], p1[600], p2[600];
int index1, index2;

double add = (1 + sqrt(5))/2;
double sub = (1 - sqrt(5))/2;

int cat(int H, int C){
    return H*H - H*C - C*C;
}

int cmp(const void *pa, const void *pb){
    struct one *a = (struct one *)pa, *b = (struct one*)pb;
    return (-a->cb/a->ca) - (-b->cb/b->ca) > 0;
}

int cmp2(const void *pb, const void *pa){
    struct one *a = (struct one *)pa, *b = (struct one*)pb;
    double k = (-a->cb/a->ca), m = (-b->cb/b->ca);
    if(k > m) return 1;
    else if( k < m) return -1;
    else return 0;
}

void dfs(int H, int C, struct one *p2, int index, int & cur, int n){
    if(index != n && index < 20)
    {
        dfs(H, C, p2, index + 1, cur, n);
        H += p2[index].a;
        C += p2[index].b;
        int k = cat(H , C);
        if( k > cur) cur = k;
        dfs(H , C , p2, index + 1, cur, n);
    }else if(index >= 20 && index != n){
        H += p2[index].a;
        C += p2[index].b;
        int k = cat(H , C);
        if( k > cur) cur = k;
        else return;
        dfs(H , C , p2, index + 1, cur, n);
    }

}

int main(){
    int repeat;
    cin >> repeat;
    while(repeat--){
        int n;
        scanf("%d", &n);
        index1 = index2 = 0;
        int H = 0, C = 0;
        for(int i=0;i<n;i++){
            scanf("%d %d", &(p[i].a), &(p[i].b));
            p[i].ca = p[i].a - add * p[i].b;
            p[i].cb = p[i].a - sub * p[i].b;

            if(p[i].ca >= 0 && p[i].cb >= 0){
                H += p[i].a;
                C += p[i].b;
            }else if(p[i].ca <= 0 && p[i].cb <= 0){

            }else{
                if(p[i].ca >= 0){
                    p[i].index = i;
                    p1[index1 ++] = p[i];
                }else{
                    p[i].index = i;
                    p2[index2++] = p[i];
                }
            }
        }
        int cur = cat(H, C);
//        if(index1 != 0){
//            qsort(p1, index1, sizeof(p1[0]), cmp);
//            int k = 0;
//            while(k < index1){
//                int ncur = cat(H + p1[k].a, C + p1[k].b);
//                if(ncur >= cur){
//                    cur = ncur;
//                    H += p1[k].a;
//                    C += p1[k].b;
//                    k++;
//                }else break;
//            }
//        }
        qsort(p2, index2, sizeof(p2[0]), cmp2);

        dfs(H, C, p2, 0, cur, index2);
//        int tor = 0;
//        if(index2 != 0){
//            qsort(p2, index2, sizeof(p2[0]), cmp2);
//            int k = 0;
//            while(k < index2){
//                int ncur = cat(H + p[p2[k].index].a, C + p[p2[k].index].b);
//                if(ncur >= cur){
//                    cur = ncur;
//                    H += p[p2[k].index].a;
//                    C += p[p2[k].index].b;
//
//                }else {
//                    if(tor++ > 100) break;
//                }
//                k++;
//            }
//        }
        cout << cur << endl;
    }
}