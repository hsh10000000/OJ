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
	int cash;
	while(cin>>cash){
		int k;
		cin>>k;
		pNode pn=new node[k];
		memset(dp,0,sizeof(dp));		
		for(int i=0;i<k;++i){
			cin>>pn[i].ni>>pn[i].di;
		}
		sort(pn,pn+k,compare);
		int ans=0;
		dp[0]=1;
		for(int i=0;i<k;++i){
			memset(cnt,0,sizeof(cnt));
			for(int j=pn[i].di;j<=cash;++j){
				if(!dp[j]&&dp[j-pn[i].di]&&cnt[j-pn[i].di]+1<=pn[i].ni){
					dp[j]=1;
					cnt[j]=cnt[j-pn[i].di]+1;
					if(j>ans){
						ans=j;
					}
				}
			}	
		}
		cout<<ans<<endl;
		delete[]pn;
	}
}
