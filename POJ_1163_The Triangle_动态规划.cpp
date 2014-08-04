#include <iostream>
#include <algorithm>
using namespace std;

void triangle(int ** &dp,int n)//数字三角形动态规划
{
	int left,right;
	for(int i=1;i<n;++i){//从第二行开始计算
		for(int j=0;j<i+1;++j){
			if(j==0){
				left=0;
				right=dp[i-1][0];
			}else if(j==i){
				left=dp[i-1][i-1];
				right=0;
			}else{
				left=dp[i-1][j-1];
				right=dp[i-1][j];
			}
			dp[i][j]+=max(left,right);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int **dp=new int *[n];
	for(int i=0;i<n;++i){
		dp[i]=new int [i+1];
		for(int j=0;j<i+1;++j){
			cin>>dp[i][j];
		}
	}
	triangle(dp,n);
	int maxi=dp[n-1][0];
	for(int i=1;i<n;++i){
		if(dp[n-1][i]>maxi){
			maxi=dp[n-1][i];
		}
	}
	cout<<maxi<<endl;
	for(int i=0;i<n;++i){
		delete [] dp[i];
	}
	delete []dp;
}
