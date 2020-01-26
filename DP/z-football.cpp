#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 10000 + 10;
const int MOD = 1e6 +7;

int dp[2][MAXN];

int main(){
    int n, m, k;

    cin >> n >> m >> k ;


    int prev = 0, now = 1;

    for(int i = 0 ; i <= n ; i ++){
        for(int j = 0 ; j <= m ; j ++){
            if(abs(i-j) > k){
                dp[now][j] = 0;
                continue;
            }
            if(i == 0 || j == 0){
                dp[now][j] = 1;
                continue ;
            }
            dp[now][j] = dp[now][j-1] + dp[prev][j];
            dp[now][j] = (dp[now][j] % MOD + MOD)%MOD;
        }    
        for(int j = 0 ; j <= m ; j ++){
           dp[prev][j] = 0;

        }
        prev ^= 1;
        now ^= 1;

    }
    cout << dp[prev][m] << endl;


}

3 ^ 5

011
101
110


0 ^ 0 = 0
1 ^ 0 = 1
0 ^ 1 = 1
1 ^ 1 = 0