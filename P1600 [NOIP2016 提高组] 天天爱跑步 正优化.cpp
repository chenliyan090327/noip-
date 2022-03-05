#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

struct T{
	int u;
	int v;
};

int n,m;

int stglong=1;
int ftglong=1;

T connect[300000];
T player[300000];
vector<int> path[300000];

int step[300000];
int see[300000];
int stg[300000];
int ftg[300000];
int seepeople[300000];


void stgf(int start){
	
	stg[stglong]=start;
	//printf("stg[%d]=%d\n",stglong,start);
	stglong++;
	if(1==start){
		return;
	}
	for(int i=1;i<=n-1;++i){
		if(start==connect[i].v){
			stgf(connect[i].u);
			return;
		}
	}
}

void ftgf(int finish){
	//printf("ftg[%d]=%d\n",ftglong,finish);
	ftg[ftglong]=finish;
	ftglong++;
	if(1==finish){
		return;
	}
	for(int i=1;i<=n-1;++i){
		if(finish==connect[i].v){
			ftgf(connect[i].u);
			return;
		}	
	}
}

void is_route(int id,int seenode){
	int start=player[id].u;
	int finish=player[id].v;
	if(path[id].size()==0){
		stglong=1;
		ftglong=1;
		memset(stg,0,sizeof(stg));
		memset(stg,0,sizeof(ftg));
		stgf(start);
		ftgf(finish);	
		int stgd=stglong-1;
		int ftgd=ftglong-1;
		int oldv=-1; 
		//printf("stgd=%d stgd=%d seenode=%d \n",stgd,ftgd,seenode);
		while(1){
			if(stg[stgd]==ftg[ftgd]){
				oldv=stg[stgd]; 
				stg[stgd]=0;
				ftg[ftgd]=0;
				stgd--;
				ftgd--;	
				if(stgd<=0){
					break;
				}
				if(ftgd<=0){
					break;
				}		
			}
			else{				
				break;
			}
		}
		if(oldv!=-1){
			stgd++;				
			stg[stgd]=oldv;				
		}
		stglong=stgd+1;
		ftglong=ftgd+1;
		for(int i=1;i<stglong;++i){								
			path[id].push_back(stg[i]);
		
		}
		for(int i=1;i<ftglong;++i){
			path[id].push_back(ftg[i]);		
		}
		//printf("create path stgd=%d stgd=%d seenode=%d \n",stgd,ftgd,seenode);
	}else{
		//printf("use path  seenode=%d\n",seenode);
	}

	for(int i=0;i<path[id].size();++i){
		//printf("player[%d]=%d vs seenode=%d \n",id,path[id][i],seenode);
		if(seenode==path[id][i]){
			seepeople[seenode]++;
			return;			
		}
	}

}

void turtle(int node,int time,int oldnode){
	if(time==0){
		//printf("turtle node %d\n",node);
		for(int i=1;i<=m;++i){
			if(player[i].u==node){
				
				//printf("turtle player %d\n",i);
				is_route(i,oldnode);
			
			}
		}
		return;
	}
	step[node]=time;
	for(int i=1;i<=n-1;++i){
		if(node==connect[i].u){
			if (step[connect[i].v]==0){
				turtle(connect[i].v,time-1,oldnode);
			}
		}
		if(node==connect[i].v){ 
			if (step[connect[i].u]==0){
				turtle(connect[i].u,time-1,oldnode);
			}
		}
	}
	return;
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n-1;++i){
		cin>>connect[i].u>>connect[i].v;
	}
	for(int i=1;i<=n;++i){
		cin>>see[i];
	}
	for(int i=1;i<=m;++i){
		cin>>player[i].u>>player[i].v;
	}
	memset(seepeople,0,sizeof(seepeople));
	for(int i=1;i<=n;++i){
		memset(step,0,sizeof(step));
		turtle(i,see[i],i);
	}
	for(int i=1;i<=n;++i){
		cout<<seepeople[i]<<" ";
	}
}
