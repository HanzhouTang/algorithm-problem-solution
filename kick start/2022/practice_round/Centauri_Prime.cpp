#include<iostream>
#include<stdio.h>
#include<string.h>
#include<unordered_set>
using namespace std; 
int main() {
    int TT; 
    scanf("%d",&TT);
    char s[125];
    unordered_set<char> vowels{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for(int ii=1;ii<=TT;ii++) {
        scanf("%s",s);
        const int len = strlen(s);
        const char ch = s[len-1];
        if(vowels.count(ch)) {
            printf("Case #%d: %s is ruled by Alice.\n",ii,s);
        } else if(ch == 'y' || ch == 'Y') {
            printf("Case #%d: %s is ruled by nobody.\n",ii,s);
        } else {
            printf("Case #%d: %s is ruled by Bob.\n",ii,s);
        }
    }
}