#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 1000 + 10;
bool ch[MAXN][MAXN];

int main(){
    int n;

    scanf("%d",&n);

    for(int i = 0 ; i < n ; i ++){
        int x, y;

        scanf("%d%d",&x,&y);
        ch[x][y] = true;
    }

    int ct = 0;

    for(int i = 0 ; i < MAXN ; i ++)
        for(int j = 0 ; j < MAXN ; j ++)
            if(ch[i][j])ct ++;

    printf("%d\n",ct);
}