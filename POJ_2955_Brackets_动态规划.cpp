#include <iostream>
#include <string>
using  namespace std;

int brackets(string &str)//poj2955 括号匹配 动态规划
{
	int maximum=0;
	int len=str.length();//字符串长度
	int **dp=new int *[len];
	for(int i=0;i<len;++i){
		dp[i]=new int [len];
		for(int j=0;j<len;++j){
			dp[i][j]=0;
		}
	}
	for(int i=2;i<=len;++i){//长度,长度从0开始
		for(int j=0;j<=len-i;++j){
			int k=j+i-1;
			if(('('==str[j] && ')'==str[k])||('['==str[j] && ']'==str[k])){//case two,(),[]				
				dp[j][k]=dp[j+1][k-1]+2;				
			}else{//不匹配
				dp[j][k]=dp[j+1][k-1];
			}

			for(int t=j;t<k;++t){//case three .()(),[][]
				if(dp[j][k]<dp[j][t]+dp[t+1][k]){
					dp[j][k]=dp[j][t]+dp[t+1][k];
				}
			}	
		}
	}
	maximum=dp[0][len-1];
	for(int i=0;i<len;++i){
		delete [] dp[i];
	}
	delete [] dp;	
	return maximum;
}

int main()
{
	string str;
	while(cin>>str){
		if("end"==str){
			break;
		}
		cout<<brackets(str)<<endl;
	}
	return 0;
}
