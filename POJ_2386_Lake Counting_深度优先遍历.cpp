#include <iostream>
using namespace std;

int dfs(char **ponds,bool **flag,int x,int y,int n,int m)//深度优先搜索
{
	if(x>=0 && x < n && y>=0 && y<m && !flag[x][y]){
		flag[x][y]=true;
		if(ponds[x][y]=='W'){
			dfs(ponds,flag,x-1,y-1,n,m);
			dfs(ponds,flag,x,y-1,n,m);
			dfs(ponds,flag,x+1,y-1,n,m);
			dfs(ponds,flag,x-1,y,n,m);
			dfs(ponds,flag,x,y,n,m);
			dfs(ponds,flag,x+1,y,n,m);
			dfs(ponds,flag,x-1,y+1,n,m);
			dfs(ponds,flag,x,y+1,n,m);
			dfs(ponds,flag,x+1,y+1,n,m);
			return 1;
		}
	}
	return 0;	
}

int main()
{
	int n,m;
	while(cin>>n>>m){
		char **ponds=new char* [n];
		bool **flag=new bool*[n];
		for(int i=0;i<n;++i){
			ponds[i]=new char [m];
			flag[i]=new bool [m];
			for(int j=0;j<m;++j){
				cin>>ponds[i][j];
				flag[i][j]=false;
			}
		}
		int count=0;

		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				count+=dfs(ponds,flag,i,j,n,m);
			}
		}
		
		cout<<count<<endl;

		for(int i=0;i<n;++i){
			delete [] ponds[i];
			delete [] flag[i];
		}
		delete [] ponds;
		delete [] flag;
	}
	return 0;
}
