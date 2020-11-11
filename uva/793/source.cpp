#include<cstdio>
#include<vector>
#include<cstring>
using namespace std; 
int find(vector<int>& a, int i) {
    if(a[i] == i){
        return a[i];
    }
    return a[i] = find(a,a[i]);
}

void combine(vector<int>& a, int i , int j) {
    a[find(a,i)] = find(a,j);
}

int main() {
    int TC; 
    scanf("%d\n",&TC);
    for(int i = 1;i<=TC;i++) {
        int n;
        scanf("\n%d\n",&n);
        vector<int> a(n+1);
        for(int i = 1;i<=n;i++) {
            a[i] = i;
        }
        char s[100];
        char ch; 
        int x, y; 
        int yes = 0;
        int no = 0;
        while(fgets(s,100,stdin)) {
            if(s[0] == '\n') {
                break;
            }
            sscanf(s,"%c %d %d\n",&ch,&x,&y);
            //printf("%c,%d,%d\n",ch,x,y);
            if(ch == 'c') {
                combine(a,x,y);
            } else if(find(a,x) == find(a,y)) {
                yes++;
            } else {
                no++;
            }
        }
        printf("%d,%d\n",yes,no);
        if(i != TC) {
            printf("\n");
        }
    }
}