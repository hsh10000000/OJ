#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool nextpermutation(char *arr,int n)
{
	int index=n-1;
	while(index>0 && arr[index-1]>=arr[index]){
		--index;
	}
	if(!index){//如果是最后一个序列，则其下一个序列为第一个序列
		//sort(arr,arr+n);
		return false;
	}
	int mp=index;
	for(int i=index+1;i<n;++i){
		if(arr[i]>arr[index-1] &&arr[i]<arr[mp]){
			mp=i;	
		}
	}
	swap(arr[index-1],arr[mp]);
	sort(arr+index,arr+n);
	return true;
}

int main()
{
	char arr[50];
	int n;
	while(cin>>arr){
		if(arr[0]=='#'){
			return 0;
		}
		int n=strlen(arr);
		if(nextpermutation(arr,n)){
			for(int i=0;i<n;++i){
				cout<<arr[i];
			}
			cout<<endl;
		}else{
			cout<<"No Successor"<<endl;
		}
	}
	return 0;
}
