#include<stdio.h>
#include<iostream>
#include<queue>
#include<stack>
#include <math.h>
#include<string.h>
using namespace std;
char c[300000];
long long sum[300000];
stack <int> S;
int main(){
	long long n;
	cin>>n;
	char niu;
	for(int i=1;i<=n;++i){
		cin>>niu;
		if(niu=='('){
			c[i]=0;
		}
		else if(niu==')'){
			c[i]=1;
		}
	}
	
	for(long long i = 1; i <= n; i ++)
		ans ^= sum[i] * i;
	cout<<ans;
}
