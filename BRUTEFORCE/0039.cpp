#include<bits/stdc++.h>

using namespace std ;

int n, m;
int ct[10],a[10];
int main(){

    scanf("%d%d",&n,&m);

    for(int i = 0 ; i < n ; i ++){
        a[i] = i + 1;
    }

    for(int i = 0 ; i < m ; i ++){
        int x;

        scanf("%d",&x);
        ct[x] ++ ;
    }

    do{
        if(!ct[a[0]]){
            for(int i = 0 ; i < n ; i ++)
                printf("%d ",a[i]);
            printf("\n");
        }
    }while(next_permutation(a,a+n));

}