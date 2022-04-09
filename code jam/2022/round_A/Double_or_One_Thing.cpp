#include<stdio.h>
#include<string>
using namespace std; 
int main() {
    int T; 
    scanf("%d",&T);
    for(int ii = 1;ii<=T;ii++) {
        char str[200];
        scanf("%s",str);
        string s(str);
        string ret; 
        const int len = s.size();
        for(int i = 0;i<len-1;i++) {
            if(s[i] < s[i+1]) {
                ret.push_back(s[i]);
            } else if(s[i] == s[i+1]) {
                int j = i + 1; 
                while(j < len && s[i] == s[j]) {
                    j++;
                }
                if(j < len && s[i] < s[j]) {
                    ret.push_back(s[i]);
                }
            }
            ret.push_back(s[i]);
        }
        ret.push_back(s.back());
        printf("Case #%d: %s\n",ii,ret.c_str());
    }
}