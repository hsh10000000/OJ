#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str1,str2;
	cin>>str1;
	while(cin>>str2){
		int len2=str2.size();
		if((len2==1)&&(str2[0]-'0'==0)){
			break;
		}
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
	cout<<str1<<endl;
}
