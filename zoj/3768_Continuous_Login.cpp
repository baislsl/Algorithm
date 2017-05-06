//
// Created by baislsl on 17-3-14.
//

#include <iostream>
#include <vector>

using namespace std;

// 超时
int main(){
    int n, max;
    vector<int> a;
    cin >> n;
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        a.push_back(k);
        if(i==0) max = k;
        if(k > max) max = k;
    }
//
//    vector<int> sum;
//    sum.push_back(0);
//    int cur = 0, addNum = 1;
//    while(cur <= max + 10){
//        cur += addNum++;
//        sum.push_back(cur);
//    }
//
    vector<vector<int > > store;
    int curIndex = 1,curResult = (curIndex*curIndex +curIndex)/2;
    for(int i=0;i<=max;i++){
        vector<int> list;
        if(i==0) store.push_back(list);
        else if(curResult == i) {
            list.push_back(curIndex);
            store.push_back(list);
            curIndex++;
            curResult = (curIndex*curIndex +curIndex)/2;
        }
        else{
            unsigned long min=0;
            int left = 1, right = i-1;
            int minLeft;
            while(left <= right){

                unsigned long num = store[left].size() + store[right].size();
                if(min == 0 || num < min){
                    min = num;
                    minLeft = left;
                }

                left++;right--;
            }
            left = minLeft;
            right = i - minLeft;
            for(int k=0;k< store[left].size();k++) list.push_back(store[left][k]);
            for(int k=0;k< store[right].size();k++) list.push_back(store[right][k]);
            store.push_back(list);
        }
    }

    for(int i=0;i<a.size();i++){
        bool flag = false;
        for(int num=0;num<store[a[i]].size();num++){
            if(!flag){
                flag = true;
                cout << store[a[i]][num];
            }else{
                cout << " " << store[a[i]][num];
            }
        }
        cout << endl;
    }

}