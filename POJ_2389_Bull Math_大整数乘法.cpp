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

int main()
{
	string str1,str2;
	while(cin>>str1>>str2){
		bigIntMulti(str1,str2);
		cout<<str1<<endl;
	}
	return 0;
}
