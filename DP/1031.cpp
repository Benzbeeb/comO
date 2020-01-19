#include<bits/stdc++.h>

using namespace std ;
const int MAXN = 10000 + 10; 
const int INF = -1u/4; 

int dp[MAXN];
vector <int> v[MAXN];

int k, n, m ;

int main(){

    scanf("%d%d%d",&k,&n,&m);

    for(int i = 0 ; i < m ; i ++){
        int x , y;

        scanf("%d %d",&x,&y);

        v[y].push_back(x);
    }

    dp[1] = 0;
    int sol = 1;
    for(int i = 2 ; i <= n ; i ++){

        dp[i] = INF ;
        for(int j = 0 ; j < v[i].size();j++){
            int x = v[i][j] ;
            dp[i] = min(dp[i],dp[x] + 1);
        }

        if(dp[i] <= k) sol = i;
        // cout <<"!" << i << endl;
    }

    printf("%d\n",sol);
}