#include <iostream>
#include <string>
#include <map>
using namespace std;

void prefix(char *pat,int *pre,int len)//KMP算法中的前缀数组
{
	int k=-1;
	pre[0]=-1;
	for(int i=1;i<len;++i){
		while(k>-1 && pat[k+1]!=pat[i]){
			k=pre[k];
		}
		if(pat[k+1]==pat[i]){
			++k;
		}
		pre[i]=k;
	}
}

void kmp(string &str,char *pat,int **dp,int **co,int m,int num)
{
	int n=str.length();
	int *pre=new int[m];
	prefix(pat,pre,m);//计算前缀数组
	int q=-1;
	for(int i=0;i<n;++i){
		while(q>-1 && pat[q+1]!=str[i]){
			q=pre[q];
		}
		if(pat[q+1]==str[i]){
			++q;
		}
		if(q==m-1){
			dp[i-m+1][i]=num;
			co[i-m+1][i]=1;
			q=pre[q];
		}
	}	
	delete []pre;
}

void print(int **pos,int **dp,string *&dict,int low,int high,int n)//递归打印结果
{
	if(low<=high){
		if(dp[low][high]!=-1 && pos[low][high]==-1){
			cout<<dict[dp[low][high]];
			if(high!=n){
				cout<<" ";
			}else{
				cout<<endl;
			}
		}else{
			print(pos,dp,dict,low,pos[low][high],n);
			print(pos,dp,dict,pos[low][high]+1,high,n);
		}
	}
}

void phone_numbers(string &str,char **dictPattern,string *&dict,int num)//poj1732,动态规划
{
	int n=str.length();//字符串的长度
	int **dp=new int *[n];
	int **co=new int *[n];
	int **pos=new int*[n];
	for(int i=0;i<n;++i){
		dp[i]=new int [n];
		co[i]=new int [n];
		pos[i]=new int[n];
		for(int j=0;j<n;++j){
			dp[i][j]=-1;
			co[i][j]=0;
			pos[i][j]=-1;
		}
	}
	for(int i=0;i<num;++i){
		kmp(str,dictPattern[i],dp,co,dict[i].size(),i);	
	}	
	for(int l=1;l<=n;++l){
		for(int i=0;i<n-l+1;++i){
			int k=i+l-1;
			if(co[i][k]==1){
				pos[i][k]=-1;
			}else{
				int mini=l;
				for(int j=i;j<k;++j){
					if(co[i][j] && co[j+1][k] && mini>co[i][j]+co[j+1][k]){
						mini=co[i][j]+co[j+1][k];
						co[i][k]=mini;
						pos[i][k]=j;
					}
				}
			}				
		}
	}
	if(co[0][n-1]){
		print(pos,dp,dict,0,n-1,n-1);
	}else{
		cout<<"No solution."<<endl;
	}
	for(int i=0;i<n;++i){
		delete [] dp[i];
		delete [] co[i];
		delete [] pos[i];
	}
	delete []dp;
	delete []co;
	delete []pos;
}

int main()
{
	string str;
	int num;
	map<char,char> ma;
	ma['o']=ma['q']=ma['z']='0';
	ma['i']=ma['j']='1';
	ma['a']=ma['b']=ma['c']='2';
	ma['d']=ma['e']=ma['f']='3';
	ma['g']=ma['h']='4';
	ma['k']=ma['l']='5';
	ma['m']=ma['n']='6';
	ma['p']=ma['r']=ma['s']='7';
	ma['t']=ma['u']=ma['v']='8';
	ma['w']=ma['x']=ma['y']='9';
	while(cin>>str>>num){
		string *dict=new string[num];
		char **dictPattern=new char*[num];
		for(int i=0;i<num;++i){
			cin>>dict[i];
			dictPattern[i]=new char [dict[i].size()+1];
			dictPattern[i][dict[i].size()]='\0';
			for(int j=0;j<dict[i].size();++j){
				dictPattern[i][j]=ma[dict[i][j]];
			}
		}
		phone_numbers(str,dictPattern,dict,num);
		delete [] dict;
		for(int i=0;i<num;++i){
			delete[]dictPattern[i];
		}
		delete [] dictPattern;
	}
}
