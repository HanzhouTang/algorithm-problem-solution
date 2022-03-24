#include<stdio.h>
using namespace std; 
int main() {
    int T;
    scanf("%d",&T);
    for(int ii = 1;ii<=T;ii++) {
        int n; 
        int m; 
        scanf("%d %d",&n,&m);
        int total = 0; 
        int x; 
        for(int i = 0;i<n;i++) {
            scanf("%d",&x);
            total += x; 
        }
        printf("Case #%d: %d\n",ii,total % m);
    }
}