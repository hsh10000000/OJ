#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void bigIntPlus(string&str1,string &str2)//大整数相加
{
	int len2=str2.size();
	int len1=str1.size();
	if(len1<len2){
		str1.insert(0,len2-len1,'0');
	}else{
		str2.insert(0,len1-len2,'0');
	}
	int idx=str1.size();
	int carry=0;int v1,v2,sum;		
	while(idx--){
		v1=str1[idx]-'0';
		v2=str2[idx]-'0';
		sum=v1+v2+carry;
		carry=0;
		if(sum>=10){
			carry=1;
			sum-=10;
		}
		str1[idx]=sum+'0';
	}
	if(carry){
		carry=0;
		str1.insert(0,1,'1');
	}	
}

void compute(string &str0,string &str1,string &str2)
{
	for(int i=3;i<102;++i){
		bigIntPlus(str0,str1);
		bigIntPlus(str0,str2);
		swap(str0,str1);
		swap(str1,str2);
	}
}

int main()
{
	string str0,str1,str2;
	while(cin>>str0>>str1>>str2){
		compute(str0,str1,str2);
		cout<<str0<<endl;
	}
	return 0;
}
