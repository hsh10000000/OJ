#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int shortest_edit_distance(string &str1,string &str2,int m,int n)
{
	int **dp=new int *[m+1];
	for (int i=0;i<=m;++i){
		dp[i]=new int [n+1];
		for(int j=0;j<=n;++j){
			dp[i][j]=0;
		}
	}
	for(int j=0;j<=n;++j){
		dp[0][j]=j;
	}
	for(int i=0;i<=m;++i){
		dp[i][0]=i;
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j){
			dp[i][j]=min(dp[i-1][j-1]+((str1[i-1]==str2[j-1])?0:1),min(dp[i][j-1],dp[i-1][j])+1);
		}
	}
	int mini=dp[m][n];
	for (int i=0;i<=m;++i){
		delete[]dp[i];
	}
	delete[]dp;
	return mini;
}


int main()
{
	string str1,str2;
	int m,n;
	while(cin>>m>>str1>>n>>str2){
		cout<<shortest_edit_distance(str1,str2,m,n)<<endl;
	}
}
