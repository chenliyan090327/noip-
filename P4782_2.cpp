#include  <cstdio>;
#include  <string.h>;
#include  <algorithm>;
#include  <stack>;
#include<iostream>
using namespace std;

const int N=2000010;
int n,m;
int cnt=0,tot=0;
int head[N]={0},dfn[N]={0},low[N]={0},col[N]={0};
bool vis[N]={0};
stack <int>st;

struct edge
{
	int next,to;
}e[N*2];

void edgeadd(int from,int to)
{
	printf("add from=%d to=%d\n",from,to);
	e[++tot].to=to;
	e[tot].next=head[from];
	head[from]=tot;
}

void tarjan(int x)
{
	dfn[x]=low[x]=++tot;
	printf("x=%d tot=%d\n",x,tot);
	st.push(x); vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
	{
		int v=e[i].to;
		if (!dfn[v])
		{
			
			tarjan(v);
			printf("111 x=%d v=%d low[x]=%d low[v]=%d\n",x,v,low[x],low[v]);
			low[x]=min(low[x],low[v]);
		}
		else if (vis[v]){
			printf("222 x=%d v=%d low[x]=%d low[v]=%d\n",x,v,low[x],low[v]);
			low[x]=min(low[x],dfn[v]);
		}
		
	}
	printf("----- x=%d \n",x);
	if (dfn[x]==low[x])
	{
		printf("x=%d cnt=%d \n",x,cnt);
		cnt++; int y;
		
		do {
			y=st.top(); st.pop();
			col[y]=cnt; vis[y]=0;
		} while (x!=y);
	}
	
}

int main()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&n,&m);
	printf("111111111111111 n=%d m=%d\n",n,m);
	for (int i=1,x,y,fx,fy;i <= m;i++)	{		
		cin>>x>>fx>>y>>fy;
		//printf("x=%d\n",x);
		edgeadd(x+n*(fx^1),y+n*fy);
		edgeadd(y+n*(fy^1),x+n*fx); 
	}
	
	tot=0;
	for (int i=1;i <=n*2;i++){	
		printf("11111\n");
		if (!dfn[i]) tarjan(i);
	}
	
	for (int i=1;i <=n;i++)
		if (col[i]==col[i+n]) return printf("IMPOSSIBLE"),0;
	printf("POSSIBLE\n");
	for (int i=1;i<=n;i++)
		if (col[i] >col[i+n]) printf("1 ");
			else printf("0 ");
	return 0;
}
