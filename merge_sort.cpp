#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

vector<int> msort(vector<int> v){

    int l = v.size();

    if(l == 1){
        return v;
    }

    int mid = l/2 ;

    vector<int> v1,v2;

    for(int i = 0 ; i < mid ; i ++)
        v1.push_back(v[i]);
    for(int i = mid ; i < l ; i ++)
        v2.push_back(v[i]);

    v1 = msort(v1);
    v2 = msort(v2);
    vector<int> ret;
    
    int s1=0,s2=0;

    while(s1 < v1.size() && s2 < v2.size()){
        if(v1[s1] < v2[s2]){
            ret.push_back(v1[s1]);
            s1++;
        }
        else{
            ret.push_back(v2[s2]);
            s2++;
        }
    }

    while(s1 < v1.size()){
        ret.push_back(v1[s1]);
        s1++;
    }

    while(s2 < v2.size()){
        ret.push_back(v2[s2]);
        s2++;
    }
    return ret;
}

int main(){
    
    scanf("%d",&n);

    for(int i = 0 ; i < n ; i ++){
        int x;
        cin >> x;
        a.push_back(x);
    }

    a = msort(a);

    for(int i = 0 ; i < n ; i ++)
        printf("%d\n",a[i]);
}
/*
5
2
1
4
5
-1
*/