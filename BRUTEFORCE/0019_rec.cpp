#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 2 ;

int a[MAXN][2];
int n ;

int rec(int k,int ct1, int ct2, bool ch){
    if(k==n){
        if(ch){
            // cout<<"#"<<ct1<<" "<<ct2<<endl;
            return abs(ct1-ct2);
        }
        return -1u/4;
    }
    return min(rec(k+1,ct1*a[k][0],ct2+a[k][1],true),rec(k+1,ct1,ct2,ch));
}
int main(){

    scanf("%d",&n);

    for(int i = 0 ; i < n ; i ++){
        scanf("%d%d",&a[i][0],&a[i][1]);
    }

    cout << rec(0,1,0,false);
}