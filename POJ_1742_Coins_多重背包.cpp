#include <iostream>
#include <algorithm>
using namespace std;
int dp[100005],cnt[100005];
typedef struct node{
	int ni;//数量
	int di;//面额
}node,*pNode;
bool compare(node a,node b)
{
	return a.di>b.di;
}
int main()
{
	int n,m;
	while(cin>>n>>m){
		if(!n&&!m){
			break;
		}
		pNode pn=new node[n];
		for(int i=0;i<n;++i){
			cin>>pn[i].di;
		}
		for(int i=0;i<n;++i){
			cin>>pn[i].ni;
		}		
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		int ans=0;
		for(int i=0;i<n;++i){
			memset(cnt,0,sizeof(cnt));
			for(int j=pn[i].di;j<=m;++j){
				if(!dp[j]&&dp[j-pn[i].di] && cnt[j-pn[i].di]+1<=pn[i].ni){
					++ans;
					dp[j]=1;
					cnt[j]=cnt[j-pn[i].di]+1;
				}
			}	
		}
		cout<<ans<<endl;
		delete[]pn;
	}
}
