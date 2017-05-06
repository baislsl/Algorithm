//
// Created by baislsl on 17-2-5.
//
#include <printf.h>
#include <climits>

int reverse(int x) {
    int ans = 0;
    int flag = 1;
    if(x < 0){
        x = -x;
        flag = -1;
    }

    while(x != 0){
        if(ans > (INT_MAX - x%10)/10)
            return 0;
        ans = ans*10 + x%10;
        x /= 10;
    }
    return flag*ans;

}