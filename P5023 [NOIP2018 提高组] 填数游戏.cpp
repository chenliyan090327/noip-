#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
int n,m,ans;
int b[13][13];
bool niu(int x,int y)
{   
    a[x][y]=a[x+1][y]|(g[x][y]<<(n-x));
    if(y==m)
        b[x][y]=0;
    else{
    	b[x][y]=b[x][y+1];
		(a[x][y+1]>>1)==a[x+1][y];
	}           
    if((x<n)&&(y>1)&&(g[x][y]==g[x+1][y-1])&&(b[x+1][y]!=0))
		return false;
	else{	                                               
    	return true;	
	}
}
void dfs(int x,int y)
{
    if(y<1){
    	dfs(x-1,m);
    	return;
	}
    if(x<1)
    {
        ans++;
        return;
    }
    if((x==n)||(y==1)||(g[x+1][y-1]==1))
    {
        g[x][y]=1;
        if(niu(x,y)){
        	dfs(x,y-1);
		}
    }
    g[x][y]=0;
    if(niu(x,y)){
    	dfs(x,y-1);
	}
}
int main()
{
    cin>>n>>m;
    dfs(n,m);
    cout<<ans;
    return 0;
}
