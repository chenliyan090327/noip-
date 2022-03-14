//https://www.luogu.com.cn/problem/P3952
#include<iostream>
#include<stdio.h>
#include <stack> 
#include<string.h>
using namespace std;
struct T {
	char i;
	bool add;
	
};
T S[100];
string tout[10];
int iline=0;
int main(){

	int t;
	cin>>t;
	int g;
	char time[10];
	char mingling;
	char xstr[10],ystr[10];	
	char i;

	//cout<<"t:"<<t<<endl;
	for(int k=0;k<t;k++){
		int if_chong=0;
		int sumn=0;
		int tmpsum=0;
		int itop = 0;
	    int noloop = -1;
		memset(time,0,sizeof(time));
		cin>>g>>time;
		//cout<<g<<" time:"<<t<<endl;
		for(int j=0;j<g;++j){
			cin>>mingling;
			//cout<<" mingling:"<<mingling<<endl;
			if(mingling=='F'){
				cin>>i>>xstr>>ystr;
				//cout<<" i:"<<i<<" x:"<<xstr<<" y:"<<ystr<<endl;				
				for(int c=0;c<itop;++c){
					if(i==S[c].i){
						if_chong=1;
						//cout<<"find double :"<<i<<endl;
					}				
				}
			
				S[itop].add=false;
				if(xstr[0]=='n'){
					S[itop].i=-1;					
					itop++;	
					noloop = itop;
					continue;
				}
				if(ystr[0]=='n'){
					if(noloop == -1){
						tmpsum++;
						S[itop].add=true;						
						if (tmpsum>sumn){
							sumn =tmpsum;
						}
					}				
				}
				S[itop].i=i;
				itop++;				
			}
			else if(mingling=='E'){			
				if (true==S[itop-1].add){
					tmpsum--;
				}
				if(noloop==itop){
					noloop = -1;
				}
				
				itop--;
								
			}
		}
		//cout<<"if_chong:"<<if_chong<<" itop:"<<itop<<" noloop:"<<noloop<<endl;
		if(if_chong==1){
			tout[iline++]="ERR";
			//cout<<"ERR"<<endl;
		}
		else{
			if(itop!=0){
				tout[iline++]="ERR";
				//cout<<"ERR"<<endl;			
			}
			else{
				//cout<<"time:"<<time<<"sumn:"<<sumn<<endl;
				if(sumn==0){
					if(time[2]=='1'){
						tout[iline++]="Yes";
						//cout<<"Yes"<<endl;
					}
					else{
						tout[iline++]="No";
						//cout<<"No"<<endl;
					}
				}
				else{
					
					if(time[4]==sumn+'0'){
						tout[iline++]="Yes";
					}
					else{
						tout[iline++]="No";
					}
				}
			}
		}
	}
	for(int k=0;k<t;k++){
		cout<<tout[k]<<endl;
	}
}
