#include<cstdio>
#include<utility>
using namespace std; 
int main(){
    int TC; 
    char s[100];
    fgets(s,100,stdin);
    sscanf(s,"%d",&TC);
    for(int i = 1;i<=TC;i++) {
        pair<long long,long long> l = {0,1};
        pair<long long,long long> r = {1,0};
        pair<long long,long long> m = {1,1};
        fgets(s,100,stdin);
        for(int i = 0;s[i];i++) {
            char ch = s[i];
            if(ch == 'L') {
                r = m; 
                m = {l.first+m.first,l.second+m.second};
            } else if(ch == 'R') {
                l = m;
                m = {r.first+m.first,r.second+m.second};
            }
        }
        printf("%lld/%lld\n",m.first,m.second);
    }
}