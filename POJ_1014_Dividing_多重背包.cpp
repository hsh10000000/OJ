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
	pNode pn=new node[6];
	int idx=0;
	while(true){
		int sum=0;
		++idx;
		for(int i=0;i<6;++i){
			cin>>pn[i].ni;
			pn[i].di=i+1;
			sum+=pn[i].ni*pn[i].di;
		}
		if(!sum){
			break;
		}
		if(sum%2){
			cout<<"Collection #"<<idx<<":"<<endl<<"Can't be divided."<<endl<<endl;
			continue;
		}
		sum/=2;
		memset(dp,0,sizeof(dp));
		sort(pn,pn+6,compare);
		dp[0]=1;
		bool flag=false;
		for(int i=0;i<6;++i){
			memset(cnt,0,sizeof(cnt));
			for(int j=pn[i].di;j<=sum;++j){
				if(!dp[j]&&dp[j-pn[i].di]&&cnt[j-pn[i].di]+1<=pn[i].ni){
					dp[j]=1;
					cnt[j]=cnt[j-pn[i].di]+1;
					if(j==sum){
						flag=true;
						break;
					}
				}
			}	
		}
		if(flag){
			cout<<"Collection #"<<idx<<":"<<endl<<"Can be divided."<<endl;
		}else{
			cout<<"Collection #"<<idx<<":"<<endl<<"Can't be divided."<<endl;
		}
		cout<<endl;
	}
	delete[]pn;
}
