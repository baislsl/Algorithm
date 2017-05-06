//
// Created by baislsl on 17-3-14.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 最多分成3个数相加
int *data = new int[32211];
int main(){
    int n;
    cin >> n;


    int sum = 0;
    for(int i=0;i<32211;){
        data[i] = sum;
        sum += ++i;
    }

    while(n--){
        int i=0;
        int num;
        cin >> num;
        bool flag = false;
        while(data[i] <= num){
            if(data[i] == num){
                cout << i << endl;
                flag = true;
                break;
            }else{
                i++;
            }
        }

        if(flag) continue;

        //data[i] > sum, data[i-1]<sum

        i--;
        int temp = i;
        int j=1;
        while(j <= i){
            int add = data[i] + data[j];
            if(add == num){
                cout << i << " " << j << endl;
                flag = true;
                break;
            }else if(add < num){
                j++;
            }else{
                i--;
            }
        }

        if(flag) continue;

        for(i=1;;i++){
            int left = i,right = temp;
            while(left <= right){
                int add = data[left] + data[right];
                if(add == num - data[i]){
                    cout << i << " " << left << " " << right << endl;
                    flag = true;
                    break;
                }else if(add < num - data[i]){
                    left ++;
                }else{
                    right --;
                }
            }
            if(flag) break;
        }



    }
}