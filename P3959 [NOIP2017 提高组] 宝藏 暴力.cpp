#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n,m;
int road[20][20];
int vis[20];
int ans=0;
int nctu[20];
int nctulong=1;

int dfs(int nd,int deep){
	//cout<<"nd="<<nd<<" deep="<<deep<<" nctulong="<<nctulong<<endl;
	if(nctulong==n){
		return 0;
	}
	int nowans=0x3f3f3f3f;
	nctu[nctulong]=nd;
	nctulong++;
	vis[nd]=deep;
	for(int k=1;k<nctulong;k++ ){
		int node=nctu[k];
		for(int i=1;i<=n;++i){
			if(road[node][i]==0){
				continue;
			}
			if (vis[i]!=0){
				continue;
			}
			//cout<<"start node="<<node<<" deep="<<vis[node]<<" i="<<i<<" nowans="<<nowans<<" nctulong="<<nctulong<<endl;
			int newwans=dfs(i,vis[node]+1)+road[node][i]*vis[node];
			//cout<<"node="<<node<<" i="<<i<<" deep="<<vis[node]<<" newwans="
			//	<<newwans<<" nowans="<<nowans<<" nctulong="<<nctulong
			//	<<" nctu: "<<nctu[0]<<" "<<nctu[1]<<" "<<nctu[2]<<endl;				
			if(newwans<nowans){
				nowans=newwans;				
			}
		}
	}
	nctulong--;
	nctu[nctulong]=0;
    vis[nd]=0;
	return nowans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		if(road[u][v]>w){
			road[u][v]=w;
			road[v][u]=w;
		}
		if(road[u][v]==0){
			road[u][v]=w;
			road[v][u]=w;
		}
	}
	for(int i=1;i<=n;++i){
		nctulong=1;
		int sum=dfs(i,1);
		//cout<<"niu:"<<i<<" "<<sum<<endl;
		if(sum<ans){
			ans=sum;
		}
		if(ans==0){
			ans=sum;
		}
	}
	cout<<ans<<endl;
}
