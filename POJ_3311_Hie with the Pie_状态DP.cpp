#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const int inf=numeric_limits<int>::max();

void floyd(int **&mat,int n)//floyd_warshall结点对最短路径算法
{
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(mat[i][j]>mat[i][k]+mat[k][j]){
					mat[i][j]=mat[i][k]+mat[k][j];
				}
			}
		}	
	}
}

void tsp(int **&mat,int n)//tsp问题，poj3311,状态dp
{
	floyd(mat,n);
	int **dp=new int*[1<<n-1];
	for(int i=0;i<(1<<n-1);++i){
		dp[i]=new int [n];
	}
	for(int i=0;i<(1<<n-1);++i){
		for(int j=1;j<n;++j){
			if(i & (1<<(j-1))){
				if((1<<(j-1))==i){
					dp[i][j]=mat[0][j];
				}else{
					dp[i][j]=inf;
					for(int k=1;k<n;++k){
						if(k!=j && (i & (1<<(k-1)))){
							dp[i][j]=min(dp[i][j],dp[i^(1<<(j-1))][k]+mat[k][j]);
						}
					}
				}
			}
		}
	}
	int ans=inf;
	for(int i=1;i<n;++i){
		ans=min(ans,dp[(1<<n-1)-1][i]+mat[i][0]);
	}
	cout<<ans<<endl;
	for(int i=0;i<(1<<n-1);++i){
		delete [] dp[i];
	}
	delete [] dp;
}

int main()
{
	int n;
	int **mat;
	while(cin>>n,n){
		mat=new int*[n+1];
		for(int i=0;i<n+1;++i){
			mat[i]=new int [n+1];
			for(int j=0;j<n+1;++j){
				cin>>mat[i][j];
			}
		}
		tsp(mat,n+1);
		for(int i=0;i<n+1;++i){
			delete [] mat[i];
		}
		delete [] mat;
	}
}
