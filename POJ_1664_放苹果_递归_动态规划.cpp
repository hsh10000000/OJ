#include <iostream>
using namespace std;

int put_apple(int m,int n)//POJ_1664递归
{
	if(m==0 || n==1){
		return 1;
	}
	if(m<n){
		return put_apple(m,m);
	}
	return put_apple(m-n,n)+put_apple(m,n-1);
}

int dp_put_apple(int m,int n)//动态规划算法
{
	int **dp=new int *[m];
	for(int i=0;i<m;++i){
		dp[i]=new int [n];
	}

	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			if(i==0 || j==0){
				dp[i][j]=1;
			}else if(j>i){
				dp[i][j]=dp[i][i];
			}else if(i==j){
				dp[i][j]=dp[i][j-1]+1;
			}else{
				dp[i][j]=dp[i-j-1][j]+dp[i][j-1];
			}
		}
	}
	int max=dp[m-1][n-1];
	for(int i=0;i<m;++i){
		delete []dp[i];
	}
	delete [] dp;
	return max;
}

int main()
{
	int g;
	cin>>g;
	int m,n;
	for(int i=0;i<g;++i){
		cin>>m>>n;
		cout<<put_apple(m,n)<<endl;
		//cout<<dp_put_apple(m,n)<<endl;
	}
	return 0;
}
