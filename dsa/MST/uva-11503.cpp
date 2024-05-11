#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 123;
int parent[N],Rank[N];

void make(int n) {
    for(int i = 0; i <= n; i++)
    {
        Rank[i] = 1; parent[i] = i;
    }
}
int find(int v){
    if(v == parent[v])
        return v;
    return find(parent[v]);
}

int Union(int a, int b) {
    a = find(a); b = find(b);
    if(a != b) {
        if(Rank[a] > Rank[b]) {
            Rank[a] += Rank[b];
            parent[b] = a;
            return Rank[a];
        }
        Rank[b] += Rank[a];
        parent[a] = b;
        return Rank[b];
    }
    return Rank[a];
}

int main(){
    int t, n, tfirst, tsecond;
    char x[30], y[30];
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        make(2*n);
        map<string, int> graph;
        int size = 0;
        while(n--) {
            scanf("%s %s", &x, &y);
            tfirst = graph[x];
            if(tfirst == 0){
                graph[x] = ++size;
                tfirst = size;
            }
            tsecond = graph[y];
            if(tsecond == 0){
                graph[y] = ++size;
                tsecond = size;
            }
            printf("%d\n", Union(tfirst, tsecond));
        }
    }
    return 0;
}
