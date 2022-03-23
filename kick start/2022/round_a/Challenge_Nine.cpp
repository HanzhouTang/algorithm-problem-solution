#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std; 
int main() {
    int T; 
    scanf("%d",&T);
    int size = 123456 + 2000;
    char s[size];
    for(int ii = 1;ii<=T;ii++) {
        scanf("%s", s);
        int total = 0; 
        const int len = strlen(s);
        for(int i = 0;i<len;i++) {
            total += s[i] - '0';
        }
        int rest = (9 - (total % 9)) % 9; 
        printf("Case #%d: ",ii);
        if(rest == 0) {
            printf("%c",s[0]);
            printf("0");
            printf("%s\n",s+1);
        } else {
            bool printed = false; 
            for(int i = 0;i<len;i++) {
                if(s[i] - '0' <= rest) {
                    printf("%c",s[i]);
                } else {
                    printed = true; 
                    printf("%d",rest);
                    printf("%s\n",s+i);
                    break;
                }
            }
            if(printed == false) {
                printf("%d\n",rest);
            }
        }
    }
}