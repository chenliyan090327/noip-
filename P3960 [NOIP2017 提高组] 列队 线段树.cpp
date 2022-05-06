#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
struct T{
	int from;
	int to;
	int siz;
	T *sonl;
	T *sonr;
	T (){
		sonl=NULL;
		sonr=NULL;
	}
};
T Trees[300001];
vector<int> dy[300001];
vector<int> rt;
int n,m,q;
int x,y;
void dfs(T *p,int pos){
	printf("p=%p pos=%d BEGIN\n",p,pos); 
	if(p->sonl!=NULL){
		if(p->sonl->siz<pos){
			dfs(p->sonr,pos-p->sonl->siz);
		}
		else{
			dfs(p->sonl,pos);
		}
		p->siz--;
		return;
	}
	if(pos==1){
		printf("p=%p pos=%d delete start\n",p,pos); 
		int value=p->from;
		cout<<value<<endl;
		p->from++;
		p->siz--;
		dy[x].push_back(rt[x]);
		rt.erase(rt.begin()+x,rt.begin()+x+1);
		rt.push_back(value);
		return;
	}
	else if(pos==p->siz){
		printf("p=%p pos=%d delete end\n",p,pos); 
		int value=p->to;
		cout<<value<<endl;
		p->to--;
		p->siz--;
		dy[x].push_back(rt[x]);
		rt.erase(rt.begin()+x,rt.begin()+x+1);
		rt.push_back(value);
		return;
	}
	else{
		printf("p=%p pos=%d CREATE\n",p,pos); 
		int value=p->from+pos-1;
		cout<<value<<endl;
		p->siz--;
		dy[x].push_back(rt[x]);
		rt.erase(rt.begin()+x,rt.begin()+x+1);
		rt.push_back(value);
		p->sonl=new T();
		p->sonr=new T();
		p->sonl->from=p->from;
		p->sonl->to=p->from+pos-2;
		p->sonl->siz=p->sonl->to-p->sonl->from+1;
		p->sonr->from=p->from+pos;
		p->sonr->to=p->to;
		p->sonr->siz=p->sonr->to-p->sonr->from+1;
		return;
	}
}
int ftree(){
	if(y==n){
		int value=rt[x];
		cout<<value<<endl;
		rt.erase(rt.begin()+x,rt.begin()+x+1);
		rt.push_back(value);
	}
	else if(Trees[x].siz>=y){
		dfs(&Trees[x],y);
	}
	else{
		int pos=y-Trees[x].siz;
		int value=dy[x][pos];
		cout<<value<<endl;
		dy[x].erase(dy[x].begin()+pos,dy[x].begin()+pos+1);
		dy[x].push_back(rt[x]);
		rt.erase(rt.begin()+x,rt.begin()+x+1);
		rt.push_back(value);
	}
}
int main(){
	cin>>n>>m>>q;
	rt.push_back(0); 
	for(int i=1;i<=n;++i){
		Trees[i].from=(i-1)*m+1;
		Trees[i].to=i*m-1;
		Trees[i].siz=m-1;
		Trees[i].sonl=NULL;
		Trees[i].sonr=NULL;
		rt.push_back(Trees[i].to+1);
	}
	for(int i=0;i<q;++i){
		cin>>x>>y;
		ftree();
		printf("ftree %d\n",i); 
	}
} 
