#include<bits/stdc++.h>

using namespace std ;
const int MAXN = 100000 + 10; 

struct Edge{
    int u,v,w;

    bool operator <(const Edge &other)const{
        return w > other.w ;
    }
};

vector<pair<int,int>> edge[MAXN];
bool visited[MAXN];
priority_queue<Edge> pq ;

int main(){
    int n, m;

    scanf("%d %d",&n,&m);

    for(int i = 0 ; i < m ; i ++){
        int u, v, w;
        scanf("%d%d%d",&u,&v,&w);
        edge[u].push_back(make_pair(v,w));
        edge[v].push_back(make_pair(u,w));
    }

    
    visited[1] = true ;
    
    for(int i = 0 ; i < edge[1].size(); i ++){
        pair<int,int> x = edge[1][i];
        pq.push({1,x.first,x.second});
    }

    while(!pq.empty()){
        int u = pq.top().u;
        int v = pq.top().v;
        int w = pq.top().w;
        pq.pop();
        // printf("!!%d %d %d\n",u,v,w);
        if(visited[v]){
            continue;
        }
        visited[v] = true;
        printf("%d %d\n",u,v);

        for(int i = 0 ; i < edge[v].size(); i ++){
            pair<int,int> x = edge[v][i];
            if(!visited[x.first]){
                pq.push({v,x.first,x.second});
            }
        }
    }
}