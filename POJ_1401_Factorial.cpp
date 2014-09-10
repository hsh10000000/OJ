#include <iostream>
using namespace std;
#define LL long long


int main()
{
	int m;
	cin>>m;
	int n;
	for(int i=0;i<m;++i){		
		cin>>n;
		int num=0;
		while(n){
			num+=n/5;
			n/=5;
		}	
		cout<<num<<endl;
		
	}
	return 0;
}
