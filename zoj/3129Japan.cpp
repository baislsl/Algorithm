#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

typedef long long ll;

struct load{
    int left, right;
};

int cmp(const void *pa, const void *pb){
    int k = ((load*)pa)->left - ((load*)pb)->left;
    if(k != 0) return k;
    else return ((load*)pa)->right - ((load*)pb)->right;
}

ll merge(load p[], int b1 , int e1, int b2, int e2 ){
    int i = 0;
    load *a1 = new load[e1 - b1 + 2];
    load *a2 = new load[e2 - b2  +2 ];
    for(i=0;i<e1-b1;i++) a1[i] = p[b1 + i];
    a1[e1-b1].right = INT_MAX;
    for( i=0;i<e2-b2;i++) a2[i] = p[b2 + i];
    a2[e2-b2].right = INT_MAX;

    int  j;
    i = j = 0;
    ll count = 0;
    for(int k=b1;k<e2;k++){
        if(a2[j].right >= a1[i].right){
            count += j;
            p[k] = a1[i++];
        }else{
            p[k] = a2[j++];
        }
    }
    delete[] a1;
    delete[] a2;
    return count;


}

ll merge_sort(load p[], int begin, int end){
    ll count = 0;
    if(begin < end - 1){
        int mid = (begin + end)/2;
        count += merge_sort(p, begin ,mid);
        count += merge_sort(p, mid, end);
        count += merge(p, begin ,mid , mid, end);
    }
    return count;
}

int main(){
    int repeat;
    cin >> repeat;
    for(int re=1;re<=repeat;re++){
        int l ,r , m;
        cin >> l >> r >> m;
        load *p =  new load[m + 10];
        for(int i=0;i<m;i++){
            cin >> p[i].left >> p[i].right;
        }

        qsort(p, m ,sizeof(load), cmp);
        ll count = merge_sort(p, 0, m);
        cout << "Test case "<< re << ": " <<  count << endl;
        delete[] p;
    }

}
