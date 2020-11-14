#include<cstdio>
#include<vector>
using namespace std; 
struct T {
    int l;
    int l_count; 
    int count; 
    int r; 
    int r_count; 
};
inline int left(int i) {
    return i<<1;
}
inline int right(int i) {
    return (i<<1) + 1;
}

T merge(const T& l, const T& r) {
    if(l.count == 0) {
        return r; 
    }
    if(r.count == 0) {
        return l; 
    }
    if(l.l == r.r) {
        int total = l.l_count+r.r_count;
        return {l.l,total,total,r.r,total};
    } 
    if(l.l == r.l) {
        int t = l.count + r.l_count; 
        return {l.l,t,max(t,r.count),r.r,r.r_count};
    }
    if(l.r == r.r) {
        int t = l.r_count + r.count; 
        return {l.l,l.l_count,max(l.count,t),l.r,t};
    }
    if(l.r == r.l) {
        return {l.l,l.l_count,max(l.count,max(r.count,l.r_count+r.l_count)),r.r,r.r_count};
    }
    return {l.l,l.l_count,max(l.count,r.count),r.r,r.r_count};
}

void build(int i, vector<T>& tree, vector<int>& a, int L, int R) {
    if(L == R) {
        tree[i] = {a[L],1,1,a[R],1};
    } else {
        int m = (L+R)/2;
        int l = left(i);
        int r = right(i);
        build(l,tree,a,L,m);
        build(r,tree,a,m+1,R);
        tree[i] = merge(tree[l],tree[r]); 
    }
}

T req(vector<T>& tree, int cur, int L, int R, int i, int j) {
    if(i>R||j<L) {
        return {0,0,0,0,0};
    }
    if(L>=i&&R<=j) {
        return tree[cur];
    }
    int m = (L+R)/2;
    T l = req(tree,left(cur),L,m,i,j);
    T r = req(tree,right(cur),m+1,R,i,j);
    return merge(l,r);
}

int main() {
    char s[100];
    while(fgets(s,100,stdin)){
        if(s[0] == '0') {
            break;
        }
        int n;
        int p; 
        sscanf(s,"%d %d",&n,&p);
        vector<int> a(n);
        for(int i = 0;i<n;i++) {
            scanf("%d",&a[i]);
        }
        vector<T> tree(4*n);
        build(1,tree,a,0,n-1);
        for(int i = 0;i<p;i++) {
            int l, r; 
            scanf("%d %d\n",&l,&r);
            T t = req(tree,1,0,n-1,l-1,r-1);
            printf("%d\n",t.count);
        }
    }
}