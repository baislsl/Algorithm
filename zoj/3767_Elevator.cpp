//
// Created by baislsl on 17-3-14.
//

#include <iostream>

using namespace std;

int main(){
    int count;
    cin >> count;
    while(count--){
        int n,m,sum = 0;
        cin >>n >> m;
        while(n--){
            int k;
            cin >> k;
            sum += k;
        }

        if(sum <= m){
            cout << "Safe\n";
        }else{
            cout << "Warning\n";
        }
    }
}