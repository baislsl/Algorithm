//
// Created by baislsl on 17-2-5.
//

#include <climits>
#include<stdio.h>

int myAtoi(char *str){
    long long ans = 0;
    int flag = 1;
    while(str[0] == ' ') str++;
    if(str[0] == '+' || str[0] == '-'){
        flag = str[0] == '-' ? -1 : 1;
        str++;
    }
    while(str[0] >= '0' && str[0] <= '9'){
        ans = ans*10 + str[0] - '0';
        if(ans*flag >INT_MAX)
            return INT_MAX;
        else if(ans*flag < INT_MIN)
            return INT_MIN;
        str++;
    }
    return flag*ans;
}

