#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100000 + 10 ;
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
vector<int> dijkstra(int st){

    vector<int> ret(n);

    fill(ret.begin() , ret.end() , INF);
    pq.push({st,0});

    while(!pq.empty()){
        int u = (pq.top()).v;
        int w = (pq.top()).w;
        pq.pop();
        if(w >= ret[u]) continue ; // check visited
        ret[u] = w ;

        for(auto next : e[u]){
            if(ret[next.v] > w + next.w) // check visited 
                pq.push({next.v,w+next.w});
        }

    }


    return ret ;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    int sum = 0 ;
    for(int i = 0 ; i < m ; i ++){

        int u , v , w;
        scanf("%d%d%d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
        sum += w ;
    }


    vector<int> stps = dijkstra(s);
    vector<int> stpt = dijkstra(t);
    int sol = 0 ;


    for(int u = 0 ; u < n ; u ++){

        for(int i = 0 ; i < e[u].size() ; i ++){
            int v = e[u][i].v ;
            sol = max(sol , sum - stps[u] - stpt[v]);
        }
    }
    cout << sol ;
}


/*
4 4
0 3
0 1 2
1 3 2
0 2 4
2 3 5

5 4
0 4
0 1 1
0 2 1
2 4 3
4 3 2

   // for(int i = 0 ; i < 2*MAXN ; i ++){
        
    //     stp[i] = 100000000 ;
    //     printf("#%d %d\n",i,stp[i]);
    // }
*/

