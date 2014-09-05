#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool subsequence(string &str1,string &str2)
{
	int len1=str1.size();
	int len2=str2.size();
	int i=0,j=0;
	while(i<len2 && j<len1){
		if(str2[i]==str1[j]){
			++i,++j;
		}else{
			++j;
		}
	}
	if(i==len2){
		return true;
	}
	return false;
}


int main()
{
	int n;
	cin>>n;
	string str1,str2;
	for(int i=0;i<n;++i){
		cin>>str1>>str2;
		if(subsequence(str1,str2)||(reverse(str2.begin(),str2.end()),subsequence(str1,str2))){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
