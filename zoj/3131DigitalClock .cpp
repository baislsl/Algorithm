#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

// no accept
int is(int h, int m, int s){
    int cc = h%10 + h/10 + m%10 + m/10 + s%10 +s/10;
    int res = 0;
    if(cc %3 ==0) res = 1;
    return res;
}
int add(int& h, int& m, int& s){
    int res = is(h,m,s);
    s += 1;
    if(s == 60){
        s = 0;
        m += 1;
        if(m == 60){
            h += 1;
            m = 0;
            if(h == 24) h = 0;
        }
    }
    return res;
}

void swap(int &a ,int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int repeat;
    cin >> repeat;
    while(repeat--){
        int h1, m1, s1, h2, m2,s2;
        scanf("%d:%d:%d %d:%d:%d",&h1,&m1,&s1, &h2,&m2,&s2);
        if(h1 == h2 && m1 == m2 && s1 == s2){
            printf("%d\n", is(h1,m1,s1));
            continue;
        }
        int count = 0;
        if(h1 < h2 || (h1 == h2 && m1 < m2) || (h1==h2 && m1==m2 && s1 <s2)){
            while(s1 != s2){
               count += add(h1, m1, s1);
            }

            count += (h2-h1)*60*20 + (m2 - m1)*20;
            count += is(h2,m2,s2);
        }else{
            swap(h1, h2);swap(m1,m2);swap(s1,s2);
            int p = is(h1,m1,s1);
            while(s1 != s2){
                count += add(h1, m1, s1);
            }

            count += (h2-h1)*60*20 + (m2 - m1)*20;
            count = 24*60*20 - count;
            count += p;
        }
        printf("%d\n",count);

    }
}//10953 + 2727 = 13680 /= 20 = 684