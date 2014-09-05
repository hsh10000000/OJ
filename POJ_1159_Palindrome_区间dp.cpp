#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int shortest_edit_distance_palindrome(string &str,int n)//区间dp
{
	int **dp=new int *[2];
	for(int i=0;i<2;++i){
		dp[i]=new int [n+1];
		for(int j=0;j<=n;++j){
			dp[i][j]=0;
		}
	}
	for(int i=n-1;i>0;--i){
		for(int j=i;j<=n;++j){
			if(str[i-1]==str[j-1]){
				dp[i%2][j]=dp[(i+1)%2][j-1];
			}else{
				dp[i%2][j]=min(dp[i%2][j-1],dp[(i+1)%2][j])+1;
			}
		}
	}
	int val=dp[1][n];
	for(int i=0;i<2;++i){
		delete [] dp[i];
	}
	delete[]dp;
	return val;
}


int main()
{
	string str;
	int n;
	while(cin>>n>>str){
		cout<<shortest_edit_distance_palindrome(str,n)<<endl;
	}
}
