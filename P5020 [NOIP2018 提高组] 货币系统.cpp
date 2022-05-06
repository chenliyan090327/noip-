#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int coin[101];
int money[25001];
int ans=0;
int maxn=0;
int main(){
	int T;
	cin>>T;
	int n;
	queue<int> q;
	for(int i=0;i<T;++i){
		memset(coin,0,sizeof(coin));
		memset(money,0,sizeof(money));
		maxn=0;
		cin>>n;
		ans=n;
		for(int j=0;j<n;++j){
			cin>>money[j];
			coin[money[j]]=-1;
			q.push(money[j]);
			if(money[j]>maxn){
				maxn=money[j];
			}
		}
		while(1){
			if(q.size()==0){
				//cout<<"niu!!!!!!!!!!!!!!!!!!!!!!!!!1"<<endl;
				break;
			}
			int num=q.front();
			//cout<<"num"<<num<<endl;
			q.pop();
			//cout<<"maxn:"<<maxn<<endl;
			for(int j=0;j<n;++j){
				int sum=money[j]+num;
				if(sum>maxn){
					//cout<<"niu!!!!!!!!!"<<endl;
					continue;
				}
				if(coin[sum]==-1){
					ans--;
					coin[sum]=0;
					continue;
				}
				q.push(sum);
			}
			//cout<<"niu!!!!!!!!!!!!!!!!!!!!!!!!!1"<<endl;
		}
		//cout<<"niu!!!!!!!!!!!!!!!!!!!!!!!!!1"<<endl;
		cout<<ans<<endl;
	}
}
