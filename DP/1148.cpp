#include<bits/stdc++.h>

using namespace std;

const int MAXM = 20000+10;

int r[MAXM], p[MAXM];
int dp[MAXM][MAXM];
int n, k, m;
int main(){

    cin >> n >> m >> k ;

    for(int i = 0; i < m ; i ++){
        scanf("%d",&r[i]);
    }

    for(int i = 0; i < k ; i ++){
        scanf("%d",&p[i]);
    }

    r[m++] = n ;

    for(int i = m-1 ; i > 0 ; i --)
        r[i] -= r[i-1];

    
    dp[0][0] = r[0]*p[0];

    for(int i = 1 ; i < m ; i ++){
       dp[i][0] = dp[i-1][0] + r[i]*p[0]; 
    }

    for(int j = 1 ; j < k ; j ++){
        dp[j][j] = dp[j-1][j-1] + r[j]*p[j];
        for(int i = j + 1 ; i < m ; i ++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + r[i]*p[j];
        }
    }
    printf("%d\n",dp[m-1][k-1]);
}
