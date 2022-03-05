#https://www.luogu.com.cn/problem/P2822
#include<iostream>
#include<stdio.h>
using namespace std;
int t,k,ans;
int answer[10000];
int anslong=0;
void C(int i,int j){
	if((i-j)<j){
		j=i-j;
	}
	int big =1;
	int little =1;
	for(int a=i;a>(i-j);--a){
		big*=a;
	}
	for(int b=j;b>0;--b){
		little*=b;
	}
	if(0== (big/little)%k){
		ans++;
	}
	
}
int main(){
	cin>>t>>k;
	int n,m;
	for(int a=0;a<t;++a){
		cin>>n>>m;
		for(int i=0;i<=n;++i){
			if(i<m){
				for(int j=0;j<=i;++j){
					C(i,j);
				}
			}
			else{
				for(int j=0;j<=m;++j){
					C(i,j);
				}
			}
		}
		answer[anslong]=ans;
		anslong++;
		ans=0;
	}
	for(int i=0;i<anslong;++i){
		cout<<answer[i]<<endl;
	}
