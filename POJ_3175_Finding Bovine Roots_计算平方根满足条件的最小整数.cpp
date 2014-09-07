#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double prec[11]={1,1e-1,1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10};

int main()
{
	int l,d;
	cin>>l>>d;
	int idx=1;
	double val=0;
	double val2=0;
	while(true){
		val=idx+d*prec[l];
		val2=val+prec[l];
		val=ceil(pow(val,2));
		val2=pow(val2,2);
		if(val2>val){
			break;
		}
		++idx;
	}
	cout.setf(ios_base::fixed);
	cout<<setprecision(0)<<val<<endl;
}
