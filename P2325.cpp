#https://www.luogu.com.cn/problem/P2827
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
int n,m,q,u,v,t;
priority_queue <int,vector<int>,less<int> > bug;
int num[10000000];
queue <int> cut;
int main(){
	cin>>n>>m>>q>>u>>v>>t;
	int x;
	for(int i=0;i<n;++i){
		cin>>x;
		bug.push(x);
	}
	for(int j=0;j<m;++j){
		int a=bug.top();
		bug.pop();
		cut.push(a);
		int b=a*u/v;
		int c=a-b;
		int niu=bug.size();
		for(int i=0;i<niu;++i){
			int sum=bug.top();
			bug.pop();
			num[i]=sum;
		}
		for(int i=0;i<niu;++i){
			bug.push(num[i]+q);
		}
		bug.push(b);
		bug.push(c);
	}
	int ans;
	int bob=cut.size();
	for(int i=1;i<=bob;i++){
		if(i%t==0){
			ans=cut.front();
			cout<<ans<<" ";	
		}
		cut.pop();	
	}
	cout<<endl;
	bob=bug.size();
	for(int i=1;i<=bob;i++){
		if(i%t==0){
			ans=bug.top();
			cout<<ans<<" ";
		}
		bug.pop();	
	}
}
