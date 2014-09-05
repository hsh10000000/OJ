#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long gcd(long long a,long long b)//求2个数的最大公约数
{
	if(b){
		return gcd(b,a%b);
	}else{
		return a;
	}
}

int main()
{
	int n;
	while(cin>>n,n){
		int *arr=new int[n];
		int val=0;
		for(int i=0;i<n;++i){
			cin>>arr[i];
			val+=arr[i];
		}
		int *hook=new int[val];
		int cnt=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<arr[i];++j){
				int t=0;
				for(int k=i+1;k<n;++k){
					if(j<arr[k]){
						++t;
					}else{
						break;
					}
				}	
				hook[cnt++]=t+arr[i]-j;
			}		
		}	
		long long multiply=1,hooksum=1;
		for(int i=0;i<val;++i){
			multiply*=(i+1);
			hooksum*=hook[i];
			long long gcdtmp=gcd(multiply,hooksum);
			multiply/=gcdtmp;
			hooksum/=gcdtmp;
		}
		cout<<multiply/hooksum<<endl;
		delete[]arr;
		delete[]hook;
	}
	return 0;
}
