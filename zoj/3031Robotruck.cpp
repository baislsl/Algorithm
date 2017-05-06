#include <iostream>
#include <climits>
#include <cmath>
#include <cstdio>
using namespace std;

typedef long long ll;

struct point{
    ll x, y;
    ll wei;
}p[100050];

ll w[100050];
ll dis[100050];

ll a[100050];

ll myDistance(int i, int j){
    return abs(p[i].x -p[j].x) + abs(p[i].y - p[j].y);
}

ll min(ll a, ll b) {
    return a > b ? b : a;
}
int main(){
    int repeat;
    cin >> repeat;
    while(repeat--){
        ll cap;
        scanf("%lld",&cap);
        //  cin >> cap;
        int n;
        //cin >> n;
        scanf("%d",&n);
        w[0] = dis[0] = 0;
        for(int i=0;i<n;i++){
            scanf("%lld%lld%lld",&(p[i].x), &(p[i].y),&(p[i].wei));
            w[i+1] = w[i] + p[i].wei;
            dis[i+1] = dis[i] + myDistance(i , i -1);
            // cin >> p[i].x >> p[i].y >> p[i].wei;
        }

        a[0] = 0;
        for(int i=0;i<n;i++){
            a[i+1] = LONG_LONG_MAX;
            ll last = 0;
            ll length = 0;
            int k = 0;
            while(true){
                ++k;
                if(k > i + 1) break;
                else{
                    if(w[i+1] - w[i+1 - k] > cap) break;
                    // last+= p[i-k+1].wei;
                    // if(last > cap) break;
                }
                a[i+1] = min(a[i+1], a[i + 1- k]  - dis[i+2-k] + dis[i+1]+ p[i-k + 1].x + p[i-k + 1].y + p[i].x + p[i].y);
                //length += myDistance(i - k, i - k + 1);


            }
        }
        //for(int i=0;i<=n;i++) cout << i << ": " << a[i] << endl;
        cout << a[n] << endl;
    }
}


