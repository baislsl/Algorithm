//
// Created by baislsl on 17-3-15.
//
#include <iostream>

using namespace std;

int main(){
    int loop;
    (cin >> loop).get();
    while(loop--){
        string input,output;
        getline(cin, input);

        for(size_t i=0;i<input.length();i++){
            char cc = input.at(i);
            switch (cc){
                case '_':output.append(input);break;
                case '!':output.append("Hello, world!");break;
                default:;
            }
        }
        if(input == output){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
