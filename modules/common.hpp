//
// Created by baislsl on 2025/7/1.
//

#ifndef COMMON_H
#define COMMON_H

#pragma region
#include <iostream>
using namespace std;

void __print(int x) { cout << x; }
void __print(long x) { cout << x; }
void __print(long long x) { cout << x; }
void __print(unsigned x) { cout << x; }
void __print(unsigned long x) { cout << x; }
void __print(unsigned long long x) { cout << x; }
void __print(float x) { cout << x; }
void __print(double x) { cout << x; }
void __print(long double x) { cout << x; }
void __print(char x) { cout << '\'' << x << '\''; }
void __print(const char *x) { cout << '\"' << x << '\"'; }
void __print(const string &x) { cout << '\"' << x << '\"'; }
void __print(bool x) { cout << (x ? "true" : "false"); }
template <size_t N>
void __print(const bitset<N>& x) { cout << x; };

template <typename T>
void __print(const T &x);
template <typename T, typename V>
void __print(const pair<T, V> &x);
template <typename T>
void __print(const T &x);
template <typename T, typename... V>
void _print(T t, V... v);

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cout << '{';
    __print(x.first);
    cout << ", ";
    __print(x.second);
    cout << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cout << '{';
    for (auto &i : x) cout << (f++ ? ", " : ""), __print(i);
    cout << "}";
}
void _print() { cout << "\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cout << ", ";
    _print(v...);
}

template<class T> bool ckmin(T&a, const T& b) { bool B = a > b; a = min(a,b); return B; }
template<class T> bool ckmax(T&a, const T& b) { bool B = a < b; a = max(a,b); return B; }
#pragma endregion

#include <bits/stdc++.h>

#endif //COMMON_H
