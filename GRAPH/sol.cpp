#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > g[100005];
int dist1[100005];
int dist2[100005];
class Compare{
public:
	bool operator()(pair<int,int> x,pair<int,int> y){
		return x.second > y.second;
	}
};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int s,t;
	scanf("%d%d",&s,&t);
	vector<pair<int,int> > ev;
	int sum = 0;
	for(int i = 0; i < m; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].emplace_back(v,w);
		g[v].emplace_back(u,w);
		ev.emplace_back(u,v);
		sum += w;
	}
	for(int i = 0; i < n; i++){
		dist1[i] = 1e9+7;
		dist2[i] = 1e9+7;
	}
	priority_queue<pair<int,int>,vector<pair<int,int> >,Compare> pq;
	dist1[s] = 0;
	pq.emplace(s,0);
	while(!pq.empty()){
		int cur = pq.top().first;
		int cw = pq.top().second;
		pq.pop();
		for(auto v : g[cur]){
			if(dist1[v.first] > cw + v.second){
				dist1[v.first] = cw + v.second;
				pq.emplace(v.first,cw + v.second);
			}
		}
	}
	dist2[t] = 0;
	pq.emplace(t,0);
	while(!pq.empty()){
		int cur = pq.top().first;
		int cw = pq.top().second;
		pq.pop();
		for(auto v : g[cur]){
			if(dist2[v.first] > cw + v.second){
				dist2[v.first] = cw + v.second;
				pq.emplace(v.first,cw + v.second);
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < m; i++){
		ans = max(ans,sum - min(dist1[ev[i].first] + dist2[ev[i].second],dist1[ev[i].second] + dist2[ev[i].first]));
	}
	printf("%d\n",ans);
	return 0;
}