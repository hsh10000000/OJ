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
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	int num1=lis(arr,n);
	reverse(arr,arr+n);
	int num2=lis(arr,n);
	num1=n-num1;
	num2=n-num2;
	cout<<(num1<num2?num1:num2)<<endl;
	delete []arr;
}
