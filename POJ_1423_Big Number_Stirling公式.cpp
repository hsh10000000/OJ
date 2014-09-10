#include <iostream>
#include <cmath>
using namespace std;
const double e = 2.7182818284590452354, pi = 3.141592653589793239;  
int main()
{
	
	int m;
	cin>>m;
	for(int i=0;i<m;++i){
		int n;
		cin>>n;
		int num=static_cast<int>(log10(sqrtf(2*pi*n))+n*log10(n/e))+1;//Stirling公式
		cout<<num<<endl;
	}
	return 0;
}
