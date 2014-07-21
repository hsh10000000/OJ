#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool comp(char a,char b)//字符串比较函数
{
	double num1=a;
	double num2=b;
	if(num1>='A' &&num1<='Z'){
		num1+=31.5;
	}
	if(num2>='A' &&num2<='Z'){
		num2+=31.5;
	}
	return ((num1-num2)>=0.0)?false:true;
}

void dfs(string &str,char *result,bool *visited,int index,int n)//poj1256,全排列,深度优先
{
	if(index==n){
		cout<<result<<endl;
	}
	for(int i=0;i<n;++i){
		if(!visited[i]){
			visited[i]=true;
			result[index]=str[i];
			dfs(str,result,visited,index+1,n);
			visited[i]=false;
			while(i+1<n && str[i]==str[i+1])++i;
		}
	}
}

int main()
{
	int n;
	cin>>n;
	string str;
	bool *visited;
	int len;
	char *result;
	for(int i=0;i<n;++i){
		cin>>str;
		len=str.size();
		visited=new bool[len];
		for(int i=0;i<len;++i){
			visited[i]=false;
		}
		result=new char[len+1];
		result[len]='\0';
		sort(str.begin(),str.end(),comp);//快速排序对字符串排序
		dfs(str,result,visited,0,len);
		delete[]visited;
		delete[]result;
	}	
}
