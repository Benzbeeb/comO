#include<bits/stdc++.h>

using namespace std ;

const int MAXN = 100000 + 10;

map<vector<int>,int> um ;
vector<int> k;
int n, p;



int main(){
    scanf("%d%d",&n,&p);

    for(int i = 0 ; i < n ; i ++){
        vector<int> a;
        
        for(int j = 0 ; j < p ; j ++){
            int x;
            scanf("%d",&x);
            a.push_back(x);
        }
        um[a] = i + 1;
    }

    for(int i = 0; i < p ; i ++){
        int x;

        scanf("%d",&x);
        k.push_back(x);
    }

    if(um.count(k)){
        printf("%d\n",um[k]);
        return 0;
    }
    else{
        // printf("!!!!");
        for(auto x : um){
            vector<int> inv_k;
            vector<int> tmp = x.first ;
            // printf("!!");
            for(int j = 0 ; j < p ; j ++){
                inv_k.push_back(k[j]-tmp[j]);
                // printf("%d ",k[j] - tmp[j]);
            }
            // printf("\n");

            if(um.count(inv_k) && um[tmp] != um[inv_k]){
                printf("%d %d\n",min(um[tmp],um[inv_k]),max(um[tmp],um[inv_k]));
                return 0;
            }
        }
    }
    printf("NO");
}