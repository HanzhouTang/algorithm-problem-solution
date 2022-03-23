#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<unordered_set>
#include<bitset>
#include<array>
using namespace std; 
// n > 5
bool f(int x, int i, char* str, array<array<int,2>,36>& m, const int n) {
    if(i == n) {
        return true; 
    }
    if(str[i] == '0') {
        if(m[x][0] != 0) {
            return f(m[x][0],i+1,str,m,n);
        }
        return false; 
    } else if(str[i] == '1') {
        if(m[x][1] != 0) {
            return f(m[x][1],i+1,str,m,n);
        }
        return false; 
    }
    auto ret = false; 
    if(m[x][0] != 0) {
        ret = f(m[x][0],i+1,str,m,n);
    }
    if(ret) {
        return true; 
    }
    if(m[x][1] != 0) {
        return f(m[x][1],i+1,str,m,n);
    }
    return false; 
}

bool g(char* str, array<array<int,2>,36>& m, const int n) {
    if(n < 5) {
        return true; 
    }
    unordered_set<int> tmp; 
    tmp.insert(0);
    for(int i = 0;i<5;i++) {
        unordered_set<int> t; 
        for(int v : tmp) {
            v <<= 1; 
            if(str[i] == '0') {
                t.insert(v);
            } else if(str[i] == '1') {
                t.insert(v|1);
            } else {
                t.insert(v);
                t.insert(v|1);
            }
        }
        swap(tmp,t);
    }
    bool ret = false; 
    for(int x : tmp) {
        if(m[x][0] != 0 || m[x][1] != 0){
            ret = f(x,5,str,m,n);
        }
        if(ret == true) {
            return true; 
        }
    }
    return false; 
}

int main() {
    int T; 
    unordered_set<int> s;
    const int limit = 1 << 5;  
    for(int i = 0; i<limit;i++) {
        bool same = true; 
        bitset<5> bits(i);
        for(int j = 0;j<=1;j++) {
            if(bits[j] != bits[4-j]) {
                same = false; 
                break; 
            }
        }
        if(same == false) {
            s.insert(i);
        }
    }
    array<array<int,2>,36> m; 
    for(int i = 0;i<36;i++) {
        if(!s.count(i)) {
            continue;
        }
        bitset<6> t(i);
        t <<= 1; 
        bool same = true; 
        for(int j = 0;j<3;j++) {
            if(t[j] != t[5-j]) {
                same = false; 
                break; 
            }
        }
        if(same == false) {
            auto x = t; 
            x[5] = 0; 
            int t = x.to_ulong();  
            if(s.count(t)) {
                m[i][0] = t; 
            }
        }
        same = true; 
        t[0] = 1; 
        for(int j = 0;j<3;j++) {
            if(t[j] != t[5-j]) {
                same = false; 
                break; 
            }
        }
        if(same == false) {
            auto x = t; 
            x[5] = 0; 
            int t = x.to_ulong();
            if(s.count(t)) {
                m[i][1] = t; 
            }
        }
    }
    scanf("%d",&T);
    const int size = 5 * 1e4 + 10; 
    char str[size];
    for(int ii = 1;ii<=T;ii++) {
        int len; 
        scanf("%d",&len);
        scanf("%s",str);
        bool tmp = g(str,m,len);
        if(tmp) {
            printf("Case #%d: POSSIBLE\n",ii);
        } else {
            printf("Case #%d: IMPOSSIBLE\n",ii);
        }
    }
}