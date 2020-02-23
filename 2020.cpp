#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 1000000 + 10;
int n;

int a[MAXN];
int last;
long long sol =0;
int main(){

    scanf("%d",&n);

    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&a[i]);

    last = a[0];
    for(int i = 1 ; i < n ; i ++){
        if(last >= a[i]){
            last = a[i];
        }
        else if(last < a[i]){
            sol += a[i] - last ;
            last = a[i];
        }
    }

    printf("%lld\n",sol);
}