#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1024];
int main()
{
	int m;
	scanf("%d",&m);
	int n,k;
	for(int i=0;i<m;++i){
		scanf("%d %d",&n,&k);
		for(int j=0;j<n;++j){
			//cin>>arr[j];
			scanf("%d",arr+j);
		}
		for(int j=0;j<k;++j){
			next_permutation(arr,arr+n);
		}
		for(int j=0;j<n-1;++j){
			printf("%d ",arr[j]);
			//cout<<arr[j]<<" ";
		}
		//cout<<arr[n-1]<<endl;
		printf("%d\n",arr[n-1]);
	}
}
