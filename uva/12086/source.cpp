#include<vector>
#include<cstdio>
using namespace std; 
inline int lastOne(int k) {
    return k&(-k);
}
void adjust(vector<int>& a, int k, int v) {
    for(;k<a.size();k+=lastOne(k)){
        a[k] += v; 
    }
}

int request(vector<int>& a, int b) {
    int sum = 0; 
    for(;b;b-=lastOne(b)) {
        sum += a[b];
    }
    return sum;
}

int rsq(vector<int>& a, int l, int r) {
    return request(a,r) - request(a,l-1);
}


int main(){
    int i = 1; 
    int n; 
    while(scanf("%d",&n)) {
        if(n == 0) {
            break; 
        }
        if(i > 1) {
            printf("\n");
        }
        printf("Case %d:\n",i++);
        vector<int> a(n+1);
        vector<int> b(n+1);
        for(int j = 1;j<=n;j++) {
            scanf("%d\n",&a[j]);
            adjust(b,j,a[j]);
        }
        char s[100];
        while(fgets(s,100,stdin)) {
            if(s[0] == 'M') {
                int x,y;
                sscanf(s,"M %d %d",&x,&y);
                printf("%d\n",rsq(b,x,y));
            } else if(s[0] == 'S') {
                int x, y; 
                sscanf(s,"S %d %d",&x,&y);
                adjust(b,x,y-a[x]);
                a[x] = y;
            } else {
                break;
            }
        }
    }
}