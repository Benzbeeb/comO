#include<bits/stdc++.h>

using namespace std ;
const int MAXN = 1000000 + 10; 

struct Edge{
    int u,v,w;

    bool operator <(const Edge &other)const{
        return w < other.w ;
    }
};

Edge e[MAXN];
int par[MAXN];

int findPar(int u){
    if(u == par[u])
        return u;
    return par[u] = findPar(par[u]);
}

int main(){
    int n, m;

    scanf("%d %d",&n,&m);

    for(int i = 1 ; i <= n ; i ++)
        par[i] = i;

    for(int i = 0 ; i < m ; i ++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }

    sort(e, e + m);
    
    for(int i = 0 ; i < m ; i ++){
        int u = e[i].u;
        int v = e[i].v;

        int parU = findPar(u);
        int parV = findPar(v);

        if(parU == parV) continue ;
        printf("%d %d\n",u,v);

        par[parU] = parV ;
    }

}