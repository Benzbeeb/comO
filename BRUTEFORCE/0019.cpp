#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 2 ;

int a[MAXN][2];

int main(){
    int n ;

    scanf("%d",&n);

    for(int i = 0 ; i < n ; i ++){
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    int sol = -1u/4;
    for(int i = 1 ; i < (1<<n) ; i ++){
        int ct1 = 1, ct2 = 0;
        for(int j = 0 ; j < n ; j ++){
            if(i & (1<<j)){
                /*
                    i = 3         -> 11 
                    j = 1 1<<j    -> 10
                    i & (1<<j)    -> 10
                */
                ct1 *= a[j][0];
                ct2 += a[j][1];
            }
        }
        sol = min(sol,abs(ct1-ct2));
    }
    cout << sol;
}