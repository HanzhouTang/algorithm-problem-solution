#include<vector>
#include<iostream>
#include<stdio.h>
#include<unordered_map>
using namespace std; 

long long f(int l, long long p, int s, vector<unordered_map<long long,unordered_map<int,long long>>>& dp) {
    if(dp[l].count(p) && dp[l][p].count(s)) {
        return dp[l][p][s];
    }
    if(l == 0){
        if(s!=0 && p % s == 0) {
            return 1; 
        }    
        return 0; 
    }
    long long ret = 0; 
    for(int i = 0;i<=9;i++) { // including 0. lol. 
        ret += f(l-1,p*i,s+i,dp);
    }
    return dp[l][p][s] = ret; 
}

int len_of(long long n) {
    int ret = 0; 
    while(n) {
        ret++; 
        n /= 10; 
    }
    return ret; 
}

int digit_at(long long n, int i) {
    // from left to right; 
    return to_string(n)[i] - '0'; 
}

long long h(long long n, int i, long long p, int s, vector<unordered_map<long long,unordered_map<int,long long>>>& dp) {
    if(i == len_of(n)) {
        if(s!=0 && p % s == 0) {
            return 1; 
        }    
        return 0; 
    }
    long long ret = 0; 
    for(int j = 0;j<digit_at(n,i);j++) {
        long long a = f(len_of(n) - i - 1, p*j, s+j,dp);
        ret += a; 
    } 
    ret += h(n,i+1,p*digit_at(n,i),s+digit_at(n,i),dp);
    return ret; 
}

long long g(long long n, vector<unordered_map<long long,unordered_map<int,long long>>>& dp) {
    if(n < 10) {
        return n; 
    }
    const int len = len_of(n);
    long long ret = 0; 
    for(int i = 1;i<len;i++) {
        for(int j = 1;j<=9;j++) {
            ret += f(i-1,j,j,dp);
        } // exclude leading zeros. 
    } 
    for(int i = 1;i<digit_at(n,0);i++) {
        ret += f(len_of(n) - 1,i,i,dp);
    }
    ret += h(n,1,digit_at(n,0),digit_at(n,0),dp);
    return ret; 
}


int main() {
    int T; 
    scanf("%d",&T);
    vector<unordered_map<long long,unordered_map<int,long long>>> dp(15);
    for(int ii = 1;ii<=T;ii++) {
        long long a; 
        long long b; 
        scanf("%lld %lld",&a,&b);
        long long r = g(b,dp);
        long long l = g(a-1,dp);
        long long ans = r - l; 
        printf("Case #%d: %lld\n",ii,ans);
    }

    
}