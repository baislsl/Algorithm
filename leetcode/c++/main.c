

#include <stdio.h>
#include <limits.h>

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

int main(){
    printf("%d",myAtoi("-1"));

}
