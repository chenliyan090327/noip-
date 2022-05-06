#include<stdio.h>
#include<iostream>
#include<queue>
#include <math.h>
#include<string.h>
using namespace std;
void dfs(int n,unsigned long long k){
	if(n==0){
		return;
	}
	unsigned long long num=pow(2,n);
	if((num/2)<=k){
		cout<<"1";
		dfs(n-1,num-k-1);
	}
	else{
		cout<<"0";
		dfs(n-1,k);
	}
}
int main(){
	int n;
	unsigned long long k;
	cin>>n>>k;
	dfs(n,k);
} 
