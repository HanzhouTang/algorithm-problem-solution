#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std; 
int main() {
    vector<int> tmp(200);
    for(int i = 0;i<=29;i++) {
        tmp[i] = 1 << i; 
    }
    for(int i = 30;i<100;i++) {
        tmp[i] = 3 + i * 2; 
    }
    int T; 
    scanf("%d",&T);
    for(int ii = 1;ii<=T;ii++) {
        int N; 
        scanf("%d",&N);
        for(int i = 0;i<100;i++) {
            printf("%d ",tmp[i]);
        }
        printf("\n");
        fflush(stdout);
        for(int i = 0;i<100;i++) {
            scanf("%d",&tmp[i+100]);
        }
        sort(tmp.begin() + 30,tmp.end());
        vector<int> a; 
        vector<int> b; 
        long long sum_a = 0; 
        long long sum_b = 0; 
        for(int i = 199;i>=0;i--) {
            if(sum_a<=sum_b) {
                a.push_back(tmp[i]);
                sum_a += tmp[i];
            } else {
                b.push_back(tmp[i]);
                sum_b += tmp[i];
            }
        }
        for(int x : a) {
            printf("%d ",x);
        }
        printf("\n");
        fflush(stdout);
    }
}