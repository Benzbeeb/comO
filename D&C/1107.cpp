#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1000000 + 10;

int a[MAXN];
int n, k, p;

bool check(int x){
    int ct = 0 ;

    for(int i = 0 ; i < n ;  i ++){
        if(a[i] > x){
            // printf("!!!!\n");
            ct++;
            i += p-1;
        }
    }
    // printf("!!%d %d\n",x,ct);
    if(ct <= k)
        return true;
    return false;
}

int bsearch(){

    int st = 0, en = -1u/4;

    while(st<=en){
        int mid = st + en >> 1;
        // printf("!%d\n",mid);
        if(!check(mid)){
            st = mid + 1;
        }
        else{
            en = mid - 1;
        }
    }

    return st;
}

int main(){
    scanf("%d%d%d",&n,&k,&p);

    for(int i = 0 ; i < n ; i ++)
        scanf("%d",&a[i]);

    printf("%d\n",bsearch());
}