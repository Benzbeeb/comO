#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 100000 + 10;

int n;
char a[MAXN];
int main(){
    scanf("%d",&n);
    scanf("%s",a);

    for(int i = 1 ; i < n ; i ++){
        if(a[i] == a[i-1]){
            printf("Wrong Answer");
            return 0;
        }
    }

    printf("Accepted");
}