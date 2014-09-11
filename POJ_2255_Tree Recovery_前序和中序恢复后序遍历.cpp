#include <iostream>
#include <string>
using namespace std;

string post_order(string &str1,string &str2)
{
	string str1l,str1r,str2l,str2r;
	string result;
	if(str1.size()){
		char root=str1[0];//root结点
		int pos=str2.find_first_of(root);		
		if(pos){
			str1l=str1.substr(1,pos);
			str2l=str2.substr(0,pos);
			result+=post_order(str1l,str2l);
		}
		if(str1.size()-pos-1){
			str1r=str1.substr(pos+1,str1.size()-pos-1);		
			str2r=str2.substr(pos+1,str2.size()-pos-1);
			result+=post_order(str1r,str2r);
		}
		result+=root;
	}
	return result;
}

int main()
{
	string str1,str2;
	while(cin>>str1>>str2){
		cout<<post_order(str1,str2)<<endl;
	}
}
