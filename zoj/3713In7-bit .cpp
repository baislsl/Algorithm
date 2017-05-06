#include <iostream>
#include <vector>
using namespace std;
class test{
public:
    int a, b;
};
int main(){
    test p;
    p.a = 0;
    p.b = 1;
    vector<test> vec;
    vec.push_back(p);
    vec[0].a = 100;
    cout << p.a;
}