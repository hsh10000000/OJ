#include <iostream>
#include <algorithm>
using namespace std;

int lis(int *&arr,int n)//最长递增子序列
{
	int *len=new int[n];
	int k=0,low=0,high=0;
	len[0]=arr[0];
	for(int i=1;i<n;++i){
		int mid,k=high;
		while(low<=high){
			mid=(low+high)>>1;
			if(len[mid]>arr[i]){
				high=mid-1;
			}else{
				low=mid+1;
			}
		}
		len[low]=arr[i];		
		high=(low>k)?low:k;
		low=0;
	}
	delete[]len;
	return high+1;
}

int main()
{
	int t,n;
	cin>>t;
	for(int k=0;k<t;++k){
		cin>>n;
		int *arr=new int[n];
		for(int i=0;i<n;++i){
			cin>>arr[i];
		}
		int num1=lis(arr,n);	
		cout<<num1<<endl;
		delete []arr;
	}
	return 0;
}
