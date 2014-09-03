#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	int pos=0;
	string str1="you";
	string str2="we";
	while(getline(cin,str)){
		pos=str.find(str1);
		while(pos!=string::npos){
			str.replace(pos,3,str2);
			pos=str.find(str1,pos+2);
		}		
		cout<<str<<endl;
	}
	return 0;
}
