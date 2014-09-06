#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void bigIntMulti(string&str1,string &str2)//大整数相加
{
	int len2=str2.size();
	int len1=str1.size();
	int *data=new int[len1+len2-1];
	memset(data,0,sizeof(int)*(len1+len2-1));
	for(int i=len1-1;i>=0;--i){
		for(int j=len2-1;j>=0;--j){
			data[i+j]+=(str1[i]-'0')*(str2[j]-'0');
		}
	}
	str1.insert(len1,len2-1,'0');
	int carry=0,sum;
	for(int i=len1+len2-2;i>=0;--i){
		sum=data[i]+carry;
		str1[i]=sum%10+'0';
		carry=sum/10;
	}
	if(carry){
		char c=carry+'0';
		str1.insert(0,1,c);
	}
	delete[]data;
}

void exponentiation(string &str,int n)//求指数
{
	if(1==n){
		return;
	}else{
		string tmp=str;
		exponentiation(str,n/2);
		bigIntMulti(str,str);
		if(n%2){			
			bigIntMulti(str,tmp);
		}
	}
}

void post_process(string &str)//去掉前导和之后的0
{
	int len=str.size();
	int pos=str.find_first_of('.');
	int cnt=0;
	for(int i=0;i<pos;++i){
		if(str[i]!='0'){
			break;
		}
		++cnt;
	}
	int cnt2=0;
	for(int i=len-1;i>pos;--i){
		if(str[i]!='0'){
			break;
		}
		++cnt2;
	}
	if(cnt2){
		str.erase(len-cnt2,cnt2);//删除后面的0
	}
	if(cnt){
		str.erase(0,cnt);
	}
	if('.'==str[str.size()-1]){
		str.erase(str.size()-1,1);
	}
}

int main()
{
	string str;
	int n;
	int pos,size;
	while(cin>>str>>n){
		int pos=str.find_first_of('.');
		str.erase(pos,1);
		size=str.size()-pos;
		exponentiation(str,n);
		pos=str.size()-size*n;
		str.insert(pos,1,'.');//插入小数点
		post_process(str);
		cout<<str<<endl;
	}
	return 0;
}
