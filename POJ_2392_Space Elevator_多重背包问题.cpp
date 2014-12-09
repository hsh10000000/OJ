#include <iostream>
#include <algorithm>
using namespace std;

typedef struct node{
	int hi;
	int ai;
	int ci;
}node,*pNode;

bool compare(node num1,node num2)
{
	return num1.ai<num2.ai;
}
int dp[40005],cnt[40005];
int main()
{
	int k;
	cin>>k;
	pNode pn=new node[k];
	for(int i=0;i<k;++i){
		cin>>pn[i].hi>>pn[i].ai>>pn[i].ci;
	}
	sort(pn,pn+k,compare);
	int ans=0;
	dp[0]=1;
	for(int i=0;i<k;++i){
		memset(cnt,0,sizeof(cnt));
		for(int j=pn[i].hi;j<=pn[i].ai;++j){
			if(!dp[j]&&dp[j-pn[i].hi]&&cnt[j-pn[i].hi]+1<=pn[i].ci){
				dp[j]=1;
				cnt[j]=cnt[j-pn[i].hi]+1;
				if(ans<j){
					ans=j;
				}
			}
		}	
	}
	cout<<ans<<endl;
	delete[]pn;
}
