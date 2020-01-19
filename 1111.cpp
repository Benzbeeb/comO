#include<bits/stdc++.h>
using namespace std ;

const int MAXN = 100000 + 10;

struct Edge{
    int v, w;
};

vector<Edge> e[MAXN];
int dis[MAXN];
bool visited[MAXN];

void DFS(int u, int d){
    visited[u] = true ;
    dis[u] = d ;

    for(auto next : e[u]){
        int v = next.v;
        int w = next.w;

        if(!visited[v])
            DFS(v,d+w);
    }
}

int main(){
    int n;

    scanf("%d",&n);

    for(int i = 0 ; i < n -1 ; i ++){
        int u, v, w;

        scanf("%d%d%d",&u,&v,&w);

        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }

    DFS(1,0);
    int sol = 0;
    for(int i = 1 ; i <= n ; i++)
        sol = max(sol,dis[i]);

    cout << sol ;
}