#include<iostream>
#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int n,m;
struct T{
	int i;
	int a;
	int j;
	int b;
};
T sat[1000000];
int oz[1000000];
int niu(int node,int sum,int lastk){
	int is_in=0;
	if(oz[node]!=0){
		if(oz[node]!=sum){
			return 0;
		}
		else{
			return 1;
		}
	}
	oz[node]=sum;
	for(int k=0;k<m;++k){
		if(lastk==k){
			continue;
		}
		if(sat[k].i==node){
			is_in=1;
			if(sum==(sat[k].a+1)){
				if(niu(sat[k].j,1,k)==0){
					return 0;
				}
				if(niu(sat[k].j,2,k)==0){
					return 0;
				}
			}
			else{
				if(niu(sat[k].j,sat[k].b+1,k)==0){
					return 0;
				}
			}
		}
		if(sat[k].j==node){
			is_in=1;
			if(sum==(sat[k].b+1)){
				if(niu(sat[k].i,1,k)==0){
					return 0;
				}
				if(niu(sat[k].i,2,k)==0){
					return 0;
				}
			}
			else{
				if(niu(sat[k].i,sat[k].a+1,k)==0){
					return 0;
				}
			}
		}
	}
	if(is_in==1){		
		oz[node]=0;	
	}
	
	return -1;
}
int main(){
	cin>>n>>m;
	int i,a,j,b;
	for(int k=0;k<m;++k){
		cin>>sat[k].i>>sat[k].a>>sat[k].j>>sat[k].b;
	}
	memset(oz,0,sizeof(oz));
	int ans=niu(1,1,-1);
	if(ans==1){
		cout<<"POSSIBLE"<<endl;
		for(int k=0;k<n;++k){
			if(oz[k]>0){
				oz[k]--;
			}
			cout<<oz[k]<<" ";
		}
		return 0;
	}
	memset(oz,0,sizeof(oz));
	ans=niu(1,2,-1);
	if(ans==1){
		cout<<"POSSIBLE"<<endl;
		for(int k=0;k<n;++k){
			if(oz[k]>0){
				oz[k]--;
			}
			cout<<oz[k]<<" ";
		}
	}
	else{
		cout<<"INPOSSIBLE"<<endl;
	}
}
