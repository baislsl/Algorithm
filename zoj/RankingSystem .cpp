//
// Created by baislsl on 17-3-17.
//
#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
struct one{
    int  score;
    long id;
    int year,month,day;
    int index;
    int rank;
};

int cmp(const void*pa, const void *pb){
    struct one *a = (one*)pa, *b = (one*)pb;

    if(a->score != b->score) return a->score - b->score;
    else if(a->year != b->year || a->month != b->month || a->day != b->day){
        return b->year*10000 + b->month *100 + b->day - a->year*10000 - a->month *100 -a->day;
    }else{
        if(b->id > a->id) return 1;
        else return -1;
    }
}

int main(){
    int repeat;
    cin >> repeat;
    while(repeat -- ){
        int n;
        cin >> n;
        one *p = (one*)malloc(n*sizeof(struct one));

        for(int i=0;i<n;i++){
            scanf("%ld %d/%d/%d %d", &(p+i)->id, &(p+i)->year,&(p+i)->month, &(p+i)->day, &(p+i)->score);
            p[i].index = i;
        }

        qsort(p,n,sizeof(struct one),cmp);
        int *a = new int[n];
        int i=0;
        while(i<n&&(p+i)->score == 0){
            a[p[i].index] = i;
            p[i].rank = 1;
            i++;
        }
        int postNum = n-i;
        int zero = 0;


        while(i<n && (n-i-zero)>(0.3*postNum + 0.000001)){
            a[p[i].index] = i;
            p[i].rank = 2;
            i++;
        }
        while(i<n && (n-i-zero)>(0.2*postNum + 0.000001)){
            a[p[i].index] = i;
            p[i].rank = 3;
            i++;
        }
        while(i<n && (n-i-zero)>(0.07*postNum + 0.000001)){
            a[p[i].index] = i;
            p[i].rank = 4;
            i++;
        }
        while(i<n && (n-i-zero)>(0.03*postNum + 0.000001)){
            a[p[i].index] = i;
            p[i].rank = 5;
            i++;
        }
        while(i<n){
            a[p[i].index] = i;
            p[i].rank = 6;
            i++;
        }
        for(int i=0;i<n;i++){
            cout << "LV" <<  p[a[i]].rank << endl;
        }

    }
}

