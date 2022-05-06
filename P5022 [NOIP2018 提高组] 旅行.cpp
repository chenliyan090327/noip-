#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> a[5001];
int n,m;
int sum;
int ans[5001];
int vis[5001];
void dfs(int u,int dad) {
	if(vis[u]==1){
		return;
	}
	vis[u]=1;
	sum+=1;
	ans[sum]=u;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(v==dad)
			continue ;
		dfs(v,u);
	}
}
int main() {
	cin>>n>>m;
	int u,v;
	for(int i=1;i<=m;i++) {
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1;i<=n;i++){
		sort(a[i].begin(),a[i].end());
	}
	dfs(1,0);
	for(int i=1;i<=sum;i++) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
