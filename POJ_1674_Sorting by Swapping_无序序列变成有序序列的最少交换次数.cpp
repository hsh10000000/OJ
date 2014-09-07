#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	int n;
	for(int k=0;k<t;++k){		
		cin>>n;
		int *arr=new int[n+1];
		bool *flag=new bool[n+1];
		int unorder=0;
		for(int i=1;i<=n;++i){
			cin>>arr[i];
			flag[i]=false;
			if(arr[i]!=i){
				++unorder;//计算无序的元素个数
			}
		}	
		int pos=1;
		int next=1;//标记下一个循环节的开始元素
		int cycle=0;
		int len=0;
		for(int i=1;i<=n;++i){			
			if(!flag[pos]){
				flag[pos]=true;
				if(pos==next){
					while(next<=n && flag[next]){
						++next;
					}
				}
				pos=arr[pos];
				++len;
			}else{
				if(len>1){
					++cycle;//增加一个循环节
				}
				len=0;				
				--i;
				pos=next;
			}
		}
		if(len>1){
			++cycle;
		}
		cout<<unorder-cycle<<endl;		
		delete []arr;
		delete []flag;
	}
	return 0;
}
