#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int nn=1500;
int dp[nn][2];

void dp_tree(vector<int> vec[],int root)//树形DP,动态规划
{
	dp[root][0]=0,dp[root][1]=1;
	for(int i=0;i<vec[root].size();++i){
		dp_tree(vec,vec[root][i]);
		dp[root][0]+=dp[vec[root][i]][1];
		dp[root][1]+=min(dp[vec[root][i]][0],dp[vec[root][i]][1]);
	}
}

int main()
{
	int n;
	int data[2];
	int root=0;
	vector<int>vec[nn];
	while(cin>>n){
		int co=0;
		for(int i=0;i<n;++i){
			scanf("%d: (%d)",&data[0],&co);
			vec[data[0]].clear();
			for(int j=0;j<co;++j){
				scanf("%d",&data[1]);
				vec[data[0]].push_back(data[1]);
			}
			if(!i){
				root=data[0];
			}
		}		
		dp_tree(vec,root);
		cout<<min(dp[root][0],dp[root][1])<<endl;
	}
	return 0;
}
