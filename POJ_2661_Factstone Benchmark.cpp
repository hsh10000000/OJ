#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int m;
	while(cin>>m,m){
		double bi=pow(2.0,(m-1960)/10+2);
		double num=0;
		int k=1;
		while(num<bi){
			num+=log(k*1.0)/log(2.0);
			++k;
		}
		cout<<k-2<<endl;
	}
	return 0;
}
