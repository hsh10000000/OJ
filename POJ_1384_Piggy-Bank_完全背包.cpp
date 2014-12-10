#include <iostream>
#include <limits>
using namespace std;
int dp[10005];
typedef struct node{
	int wi;//重量
	int di;//面额
}node,*pNode;

int main()
{
	int t;
	cin>>t;
	for(int a=0;a<t;++a){
		int emp,ful;
		cin>>emp>>ful;
		int k;
		cin>>k;
		int sum=ful-emp;
		pNode pn=new node[k];
		for(int i=0;i<k;++i){
			cin>>pn[i].di>>pn[i].wi;
		}
		for(int i=0;i<=sum;++i){
			dp[i]=numeric_limits<int>::max();
		}
		dp[0]=0;
		for(int i=0;i<k;++i){
			for(int w=0;w<=sum;++w){
				if(w>=pn[i].wi){
					if(dp[w-pn[i].wi]!=numeric_limits<int>::max()){
						dp[w]=min(dp[w],dp[w-pn[i].wi]+pn[i].di);
					}
				}
			}
		}
		if(dp[sum]==numeric_limits<int>::max()){
			cout<<"This is impossible."<<endl;
		}else{
			cout<<"The minimum amount of money in the piggy-bank is "<<dp[sum]<<"."<<endl;
		}

	}
}
