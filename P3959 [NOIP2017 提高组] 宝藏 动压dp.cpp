#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
const int N=12+2;
const int M=1<<N;
int n,m;
int road[N][N],trans[M][M];
long long f[N][M]; 


int main(){
	cin>>n>>m;
	memset(road,0x3f,sizeof(road)); 
	for(int i=1;i<=m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		if(road[u][v]>w){
			road[u][v]=w;
			road[v][u]=w;
		}	
	}
	//printf("n=%d m=%d\n",n,m);
	//memset(trans,0,sizeof(trans)); 
    for(int i=0;i<(1<<n);i++){		//遍历状态
	    for(int j=i;j!=0;j=(j-1)&i){//状态j为状态i子状态，
	        bool OK=true;
	        int temp=i^j;//状态i与状态j的不同之处，状态转移为j->i 
	        for(int g=n-1;g>=0;g--)   {	     
	        	if((temp>>g)&1){//说明点k是转移中增加的点，即 j没有，i有 	            
	                int tmin=INF;
	                for(int L=1;L<=n;L++){
	                	if(1&(j>>(L-1))){ //如果状态j包含此点 ,求出L到g+1的最短距离
	                    	//if(((1<<(L-1))&j)==(1<<(L-1))) 
	                        tmin=min(tmin,road[L][g+1]);
	                	}
					} 	 
					//printf("trans[%d][%d] tmin=%x\n",n,m,tmin);                  	                        
	                if(tmin==INF){// 如果此路无法走通   状态j到状态i 不可能   
						trans[j][i]=INF;
						//printf(" trans[%d][%d]=%x\n",n,m,trans[j][i]);  							                    
	                    break;
	                }	            
	                trans[j][i]+=tmin; // 状态j到状态i的最小开销  
					//printf("trans[%d][%d]=%x\n",n,m,trans[j][i]);     
	            }
			}	
			if(OK==false)
                trans[j][i]=0x3f3f3f3f;       
	    }
	} 
	memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)  // 从一层为免费 
        f[1][(1<<(i-1))]=0;
        
    for(int k=2;k<=n;k++){  // 由底至上DP，从2层开计算 
    	for(int i=0;i<(1<<n);i++){	//遍历状态
	    	for(int j=i;j!=0;j=(j-1)&i){ //状态j为状态i子状态，
	    		if(trans[j][i]!=INF){  //使用计算 
	    			f[k][i]=min(f[k][i],f[k-1][j]+(k-1)*trans[j][i]);
	    		}
	    	}
	    }
	}    
    long long ans=LINF;
    for(int k=1;k<=n;k++)  // 查找不同层级 所有联通的最小值 
        ans=min(ans,f[k][(1<<n)-1]);
	
	cout<<ans<<endl;
}
