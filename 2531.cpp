#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#define INF ((int)1e9)

using namespace std;

typedef pair<int, int> vec;

class SegmentTree{
private:
    vector<int> lo, hi, A;
    int n;
    int left(int p) {
        return (p << 1) + 1;
    }
    int right(int p){
        return (p << 1) + 2;
    }

    void build(int p, int l, int r){
        if(l == r) lo[p] = hi[p] = A[l];
        else{
            build(left(p), l, (l+r)/2);
            build(right(p), (l+r)/2+1, r);
            lo[p] = min(lo[left(p)], lo[right(p)]);
            hi[p] = max(hi[left(p)], hi[right(p)]);
        }
    }
    vec query(int p, int l, int r, int i, int j){
        if(i > r || j < l){
            return {INF, -INF};
        }
        if(l >= i && r <= j){
            return {lo[p], hi[p]};
        }
        vec a = query(left(p), l, (l+r)/2, i, j);
        vec b = query(right(p), (l+r)/2+1, r, i, j);
        return {min(a.first, b.first), max(a.second, b.second)};
    }
    void update(int p, int l, int r, int index, int nval){
        int i = index, j = index;
        if(i > r || j < l) return;
        if(l == i && r == j){
            A[i] = nval;
            lo[p] = hi[p] = A[l];
            return;
        }
        update(left(p), l, (l+r)/2, index, nval);
        update(right(p), (l+r)/2+1, r, index, nval);
        lo[p] = min(lo[left(p)], lo[right(p)]);
        hi[p] = max(hi[left(p)], hi[right(p)]);
    }
public:
    SegmentTree(const vector<int> &vA){
        A = vA;
        n = (int)A.size();
        lo.assign(4*n, 0);
        hi.assign(4*n, 0);
        build(0, 0, n-1);
    }
    int query(int i, int j){
        vec ans = query(0, 0, n-1, i, j);
        return ans.second - ans.first;
    }
    void update(int i, int val){
        update(0, 0, n-1, i, val);
    }
};

int main(){
    int N, Q, c, i, j;
    while(scanf("%d", &N) != EOF){
        vector<int> p(N, 0);
        for(i = 0; i < N; i++){
            scanf("%d", &p[i]);
        }
        SegmentTree st(p);
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d %d", &c, &i, &j);
            if(c == 1)
                st.update(i-1, j);
            else{
                i--, j--;
                printf("%d\n", st.query(min(i, j), max(i, j)));
            }
        }
    }
    return 0;
}
