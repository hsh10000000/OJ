#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr1[102];
int arr2[102];
int num1=0,num2=0;
bool cmp(int a,int b)
{
	return a<b;
}
void pruduct(int n,int k)
{
	if(num1>1){
		sort(arr1,arr1+num1,cmp);//数据排序
	}
	if(num2>1){
		sort(arr2,arr2+num2,cmp);//数据排序
	}
	vector<int>vec;
	int idx1=num1-1,idx2=0;
	if(k&1){
		if(num1){
			vec.push_back(arr1[idx1]);
			--idx1;
			--k;
		}else{
			for(int i=num2-1;i>=num2-k;--i){
				vec.push_back(arr2[i]);
			}
			k=0;
		}
	}
	for(int i=0;i<k;i+=2){
		if(idx1-1>=0 && idx2+1<num2){//通用情况
			if(arr1[idx1]*arr1[idx1-1]>arr2[idx2]*arr2[idx2+1]){
				vec.push_back(arr1[idx1]);
				vec.push_back(arr1[idx1-1]);
			}else{
				vec.push_back(arr2[idx2]);
				vec.push_back(arr2[idx2+1]);
			}
			idx1-=2,idx2+=2;
		}else if(idx1-1>=0){
			vec.push_back(arr1[idx1]);
			vec.push_back(arr1[idx1-1]);
			idx1-=2;
		}else if(idx2+1<num2){
			vec.push_back(arr2[idx2]);
			vec.push_back(arr2[idx2+1]);
			idx2+=2;
		}
	}
	sort(vec.begin(),vec.end());
	for(int i=vec.size()-1;i>=0;--i){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

int main()
{
	int n,k;
	cin>>n>>k;	
	int data;
	for(int i=0;i<n;++i){
		cin>>data;
		if(data>=0){
			arr1[num1++]=data;
		}else{
			arr2[num2++]=data;
		}		
	}
	pruduct(n,k);	
}
