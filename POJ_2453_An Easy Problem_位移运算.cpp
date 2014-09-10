#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin>>n,n){
		int low=n&(-n);
		int n_new=n+low;
		int xo=n^n_new; 
		int bi=(xo>>2)/low;
		int ans=n_new|bi;
		cout<<ans<<endl;
	}
	return 0;
}
