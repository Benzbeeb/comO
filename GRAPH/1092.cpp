#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 100000 + 10;
int n, m;

int parent[MAXN];
int a[MAXN];

int findPar(int x){
    
    if(x == parent[x])
        return x;
    
    return parent[x] = findPar(parent[x]);
}

int main(){
    scanf("%d %d",&n,&m);

    for(int i = 1 ; i <= n ; i ++){
        scanf("%d",&a[i]);
        parent[i] = i;
    }

    for(int i = 0 ; i < m ; i ++){
        int x, y ;
        scanf("%d%d",&x,&y);
        if(findPar(x) == findPar(y)){
            printf("-1\n");
            continue ;
        }

        if(x > y) swap(x,y);
        
        int winner , loser ;

        if(a[findPar(x)] >= a[findPar(y)]){
            winner = x ;
            loser = y ;
        }
        else{
            winner = y;
            loser = x;
        }

        parent[loser] = findPar(winner);
        a[findPar(winner)] += a[findPar(loser)]/2;
        
        printf("%d\n",findPar(winner));
    }



}