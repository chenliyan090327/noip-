#include<stdio.h>
#include<iostream>
using namespace std;
int n;
int niu[100001];
long long ans=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>niu[i];
	}     
	ans=niu[1];
	for(int i=2;i<=n;i++){
		if(niu[i]>niu[i-1]){
			ans=ans+niu[i]-niu[i-1];
		}
	}     
	cout<<ans;
	return 0;
}
