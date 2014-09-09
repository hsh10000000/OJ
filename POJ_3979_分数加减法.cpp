#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int gcd(int a,int b)//最大公约数
{
	if(!b){
		return a;
	}
	return gcd(b,a%b);
}

int main()
{
	string str;
	while(getline(cin,str)){
		int n1x,n1y,n2x,n2y;
		char op;
		int pos=0,pos2=0;
		pos2=str.find_first_of('/',pos);
		n1x=atoi(str.substr(0,pos2-pos).c_str());
		pos=str.find_first_of("+-",pos2+1);
		n1y=atoi(str.substr(pos2+1,pos-pos2).c_str());
		op=str[pos];
		pos2=str.find_first_of('/',pos+1);
		n2x=atoi(str.substr(pos+1,pos2-pos).c_str());
		n2y=atoi(str.substr(pos2+1).c_str());
		int fz1=n1x*n2y,fz2=n2x*n1y;
		int fm=n1y*n2y;
		int fz;
		if('+'==op){
			fz=fz1+fz2;
		}else{
			fz=fz1-fz2;
		}
		int g=gcd(abs(fz),fm);
		if(fz){
			cout<<fz/g;
			if(fm/g!=1){
				cout<<"/"<<fm/g;
			}
			cout<<endl;
		}else{
			cout<<0<<endl;
		}
	}
	return 0;
}
