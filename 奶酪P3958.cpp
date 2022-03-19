#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct T{
	int x;
	int y;
	int z;
};
T dong[1000];
int bcj[1000];
long long n,h,r;
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;++i){
		for(int j=0;j<=1000;++j){
			dong[j].x=0;
			dong[j].y=0;
			dong[j].z=0;
			bcj[j]=j;
		}
		cin>>n>>h>>r;
		for(int j=1;j<=n;++j){
			cin>>dong[j].x>>dong[j].y>>dong[j].z;
			if((dong[j].z-r)<=0){
				bcj[j]=-1;
			}
		}
		for(int j=1;j<=n;++j){
			if(bcj[j]==-1){
				continue;
			}
			for(int k=1;k<=n;++k){
				if(k==j){
					continue;
				}
				if(((dong[j].x-dong[k].x)*(dong[j].x-dong[k].x)+(dong[j].y-dong[k].y)*(dong[j].y-dong[k].y)+(dong[j].z-dong[k].z)*(dong[j].z-dong[k].z))<=((2*r)*(2*r))){
					if(bcj[k]==-1){
						for(int u=1;u<=n;++u){
							if(bcj[u]==bcj[j]){
								bcj[u]=-1;
							}
						}
						bcj[j]=-1;
					}
					else{
						bcj[k]=bcj[j];
					}
				}
			}
		}
		bool niu=false;
		for(int j=1;j<=n;++j){
			if((dong[j].z+r)>=h){
				if(bcj[j]==-1){
					cout<<"Yes"<<endl;
					niu=true;
					break;
				}
			}
		}
		if(niu==false){
			cout<<"No"<<endl;
		}
	}
}
