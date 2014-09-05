#include <iostream>
#include <string>
#include <vector>
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

void fibs(vector<string> &vec,int n)
{
	string str1="1",str2="2";
	vec.push_back(str1),vec.push_back(str2);
	while(str1.size()<n+2){
		bigIntPlus(str1,str2);
		vec.push_back(str1);
		swap(str1,str2);
	}
}

int compare(string &str1,string str2)//比较字符串大小函数
{
	int len1=str1.size(),len2=str2.size();
	if(len1<len2){
		return -1;//str1<str2
	}else if(len1>len2){
		return 1;//str1>str2;
	}else{
		for(int i=0;i<len1;++i){
			if(str1[i]>str2[i]){
				return 1;
			}else if(str1[i]<str2[i]){
				return -1;
			}
		}
		return 0;//两个字符串相等
	}
}

int binary_search(vector<string>&vec,string &str)//二分查找
{
	int low=0;
	int high=vec.size();
	while(low<=high){
		int mid=(low+high)>>1;
		if(-1==compare(vec[mid],str)){
			low=mid+1;
		}else if(1==compare(vec[mid],str)){
			high=mid-1;
		}else{
			return mid;
		}
	}
	return low;	
}

int main()
{
	vector<string>vec;
	fibs(vec,100);
	string str1,str2;
	while(cin>>str1>>str2){
		if("0"==str1 && "0"==str2){
			return 0;
		}
		int low=binary_search(vec,str1);
		int high=binary_search(vec,str2);
		int len=high-low;
		if(vec[high]==str2){
			len+=1;
		}
		cout<<len<<endl;
	}
	return 0;
}
