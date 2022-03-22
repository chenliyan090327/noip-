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
    for(int i=0;i<(1<<n);i++){		//����״̬
	    for(int j=i;j!=0;j=(j-1)&i){//״̬jΪ״̬i��״̬��
	        bool OK=true;
	        int temp=i^j;//״̬i��״̬j�Ĳ�֮ͬ����״̬ת��Ϊj->i 
	        for(int g=n-1;g>=0;g--)   {	     
	        	if((temp>>g)&1){//˵����k��ת�������ӵĵ㣬�� jû�У�i�� 	            
	                int tmin=INF;
	                for(int L=1;L<=n;L++){
	                	if(1&(j>>(L-1))){ //���״̬j�����˵� ,���L��g+1����̾���
	                    	//if(((1<<(L-1))&j)==(1<<(L-1))) 
	                        tmin=min(tmin,road[L][g+1]);
	                	}
					} 	 
					//printf("trans[%d][%d] tmin=%x\n",n,m,tmin);                  	                        
	                if(tmin==INF){// �����·�޷���ͨ   ״̬j��״̬i ������   
						trans[j][i]=INF;
						//printf(" trans[%d][%d]=%x\n",n,m,trans[j][i]);  							                    
	                    break;
	                }	            
	                trans[j][i]+=tmin; // ״̬j��״̬i����С����  
					//printf("trans[%d][%d]=%x\n",n,m,trans[j][i]);     
	            }
			}	
			if(OK==false)
                trans[j][i]=0x3f3f3f3f;       
	    }
	} 
	memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)  // ��һ��Ϊ��� 
        f[1][(1<<(i-1))]=0;
        
    for(int k=2;k<=n;k++){  // �ɵ�����DP����2�㿪���� 
    	for(int i=0;i<(1<<n);i++){	//����״̬
	    	for(int j=i;j!=0;j=(j-1)&i){ //״̬jΪ״̬i��״̬��
	    		if(trans[j][i]!=INF){  //ʹ�ü��� 
	    			f[k][i]=min(f[k][i],f[k-1][j]+(k-1)*trans[j][i]);
	    		}
	    	}
	    }
	}    
    long long ans=LINF;
    for(int k=1;k<=n;k++)  // ���Ҳ�ͬ�㼶 ������ͨ����Сֵ 
        ans=min(ans,f[k][(1<<n)-1]);
	
	cout<<ans<<endl;
}
