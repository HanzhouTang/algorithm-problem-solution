#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std; 
int main() {
    int T; 
    scanf("%d",&T);
    int size = 1e5 + 10;
    char s[size];
    char s1[size];
    for(int ii = 1;ii<=T;ii++) {
        scanf("%s\n",s);
        scanf("%s\n",s1);
        int i = 0; 
        int j = 0; 
        while(i<strlen(s) && j < strlen(s1)) {
            if(s[i] == s1[j]) {
                i++; 
                j++; 
            } else {
                j++; 
            }
        } 
        if(i == strlen(s)) {
            printf("Case #%d: %d\n",ii,(int)(strlen(s1) - strlen(s)));
        } else {
            printf("Case #%d: IMPOSSIBLE\n",ii);
        }
    }
}