#include<stdio.h>
#include<string>
#include<array>
#include<vector>
#include<stack>
#include<iostream>
#include<numeric>
#include<climits>
using namespace std; 

int C(int l, int r, vector<vector<int>>& input, vector<vector<int>>& m) {
    if(m[l][r] != -1) {
        return m[l][r];
    }
    vector<int> a = input[l];
    for(int i = l + 1;i<=r;i++) {
        for(int j = 0;j<input[i].size();j++) {
            a[j] = min(a[j],input[i][j]);
        }
    }
    return m[l][r] = accumulate(a.begin(),a.end(),0);
}

int f(int l, int r, vector<vector<int>>& input, vector<vector<int>>& dp,vector<vector<int>>& m) {
    if(l == r) {
        return 0; 
    }
    if(dp[l][r] != -1) {
        return dp[l][r];
    }
    int ret = INT_MAX; 
    for(int i = l;i<r;i++) {
        int tmp = f(l,i,input,dp,m) + f(i+1,r,input,dp,m) + (C(l,i,input,m) + C(i+1,r,input,m) - 2 * C(l,r,input,m)) * 2; 
        ret = min(ret,tmp);
    }
    return dp[l][r] =  ret; 
}

int main() {
    int T; 
    scanf("%d",&T);
    for(int ii = 1;ii<=T;ii++) {
       int E, W; 
       scanf("%d %d",&E,&W);
       vector<vector<int>> input(E+2,vector<int>(W));
       for(int i = 1;i<=E;i++) {
           for(int j = 0;j<W;j++) {
               scanf("%d",&input[i][j]);
           }
       }
       vector<vector<int>> m(E+2,vector<int>(E+2,-1));
       vector<vector<int>> dp(E+2,vector<int>(E+2,-1));
       int ans = f(0,E+1,input,dp,m);
       printf("Case #%d: %d\n",ii,ans);
    }
}