#include <iostream>
#include <vector>
using namespace std;
typedef struct node{
	int p,w;
}node;
vector<node> vec[400002];
void dfs(bool *&visit,int idx,int sum,int &maxi,int &k)
{
	if(sum>maxi){
		maxi=sum,k=idx;
	}
	for(int i=0;i<vec[idx].size();++i){
		if(!visit[vec[idx][i].p-1]){
			visit[vec[idx][i].p-1]=true;
			dfs(visit,vec[idx][i].p,sum+vec[idx][i].w,maxi,k);
			visit[vec[idx][i].p-1]=false;
		}
	}
}


int main()
{
	int n,m;
	bool *visit;
	while(cin>>n>>m){		
		for(int i=1;i<=n;++i){
			vec[i].clear();
		}
		visit=new bool[n];
		memset(visit,0,n*sizeof(bool));
		int x,y;
		char  ch;
		node tmp;
		for(int i=0;i<m;++i){
			cin>>x>>y>>tmp.w>>ch;
			tmp.p=y,vec[x].push_back(tmp);
			tmp.p=x,vec[y].push_back(tmp);
		}
		int sum=0,maxi=0,idx=0,idx2=0;
		visit[0]=true;
		dfs(visit,1,sum,maxi,idx);
		memset(visit,0,n*sizeof(bool));
		visit[idx-1]=0;
		dfs(visit,idx,sum,maxi,idx2);
		cout<<maxi<<endl;
		delete[]visit;
	}
}
