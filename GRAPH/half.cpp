#include<bits/stdc++.h>

using namespace std ; 

const int MAXN = 100000 + 10 ;
const int MAX2N = 100000*2 + 10;
const int INF = -1u/4 ;

struct Edge{
    int v , w ;
    bool operator <(const Edge  &o)const{
        return w > o.w ;
    }
};

vector<Edge> e[MAXN];

int n , m ;
int s , t ;
priority_queue<Edge> pq ;
int stp[2*MAXN];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    cout << "->" << n << " " << m << endl;
    for(int i = 0 ; i < m ; i ++){

        int u , v , w;
        scanf("%d%d%d",&u,&v,&w);
        printf("!!%d %d %d %d\n",i,u,v,w);

        e[u].push_back({v,w});
        printf("--\n");
    }
    printf("!asd\n");
    for(int i = 0 ; i < 2*MAXN ; i ++){
        
        stp[i] = 100000000 ;
        // printf("#%d %d\n",i,stp[i]);
    }
    printf("!!!!!!!!");
    stp[s] = 0 ;

    pq.push({s,stp[s]});

    while(!pq.empty()){
        int u = pq.top().v;
        int cost = pq.top().w;

        if(cost >= stp[u]) continue ;
        stp[u] = cost;

        for(auto next: e[u]){
            int next_cost = cost + next.w;
            if(stp[next.v] > next_cost)
                pq.push({next.v,next_cost});
        }

        if(u < MAXN){
            for(auto next: e[u]){
            int next_cost = cost + next.w/2;
            if(stp[next.v+MAXN] > next_cost)
                pq.push({next.v+MAXN,next_cost});
            }
        }
    }

    cout << stp[t+MAXN] << endl;

}

/*
4 5
0 3
0 1 2
1 2 2
1 3 2
3 1 2
0 3 100

*/