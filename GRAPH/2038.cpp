#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 200 + 10;
int n, m;
int par[MAXN];

struct Edge{
    int u, v, w;

    Edge(){}
    Edge(int uu, int vv, int ww){
        u = uu;
        v = vv;
        w = ww;
    }

    bool operator <(const Edge &other)const{
        if(w != other.w)return w < other.w;
        if(v != other.v)return v < other.v;
        return u < other.u;
    }
};

set<Edge> mst;

int findPar(int u){
    if(u == par[u]){
        return u;
    }

    return par[u] = findPar(par[u]);
}

int main(){

    scanf("%d%d",&n,&m);

    for(int i = 1 ; i <= n ; i ++){
        par[i] = i;
    }
   
    for(int i = 0 ; i < m ; i++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        for(int j = 1 ; j <= n ; j ++){
            par[j] = j;
        }
        mst.insert({u,v,w});
    

        int ne = 0 ;
        int cost = 0 ;
        bool del = false ;
        set<Edge>::iterator rmv ; 
        for(set<Edge>::iterator it = mst.begin(); it != mst.end();it ++){
            int x, y, z;
            x = it->u;
            y = it->v;
            z = it->w;
            
        
            int parX = findPar(x);
            int parY = findPar(y);
            if(parX == parY){
                del = true ;
                rmv  = it ;
                continue ;
            }

            ne ++;
            cost += z;

            par[parX] = parY ;
        }

        if(del){
            mst.erase(rmv);
        }    

        if(ne < n-1)
            printf("-1\n");
        else
            printf("%d\n",cost);
        
    }
}