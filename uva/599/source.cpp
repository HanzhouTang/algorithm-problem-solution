#include<cstdio>
#include<bitset>
using namespace std; 
int main() {
    int TC; 
    scanf("%d\n",&TC);
    for(int i = 1;i<=TC;i++) {
        char s[100];
        bitset<26> bits; 
        int e = 0;
        while(fgets(s,100,stdin)) {
            if (s[0] == '(') {
                char a,b;
                sscanf(s,"(%c,%c)\n",&a,&b);
                bits[a-'A'] = 1;
                bits[b-'A'] = 1;
                e++;
            } else if(s[0] != '*') {
                int acorn = 0; 
                int v = 0;
                for(int i = 0;s[i];i++) {
                    if(s[i]>='A' && s[i]<= 'Z') {
                        v++;
                        if(!bits[s[i]-'A']) {
                            acorn++;
                        }
                    }
                }
                int total = v - e;
                printf("There are %d tree(s) and %d acorn(s).\n",total - acorn,acorn);
                break;
            }
        }
    }
}