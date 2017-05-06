//
// Created by baislsl on 17-2-3.
//
// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
#include <string.h>
#include <malloc.h>

int findOdd(int i,char *s){
    int count = 1;
    int left = i - 1,right = i + 1;
    while(left != -1&&s[right] && s[left] == s[right]){
        count += 2;
        left--;
        right++;
    }
    return count;
}

int findEven(int i,char *s){
    int count = 0;
    int left = i,right = i + 1;
    while(left != -1&&s[right] && s[left] == s[right]){
        count += 2;
        left--;
        right++;
    }
    return count;
}

char* longestPalindrome(char* s) {
    int max = 1,beginIndex=0;
    int length = strlen(s);

    for(int i=0; i < length ;i++){
        int odd = findOdd(i,s);
        int even = findEven(i,s);
        if(odd>max){
            beginIndex = i - odd/2;
            max = odd;
        }
        if(even>max){
            beginIndex = i + 1 - even/2;
            max = even;
        }
    }

    char *ans = (char*)malloc((max+1)*sizeof(char));
    int ansIndex = 0;
    while(max--){
        ans[ansIndex++] = s[beginIndex++];
    }
    ans[ansIndex] = 0;
    return ans;

}