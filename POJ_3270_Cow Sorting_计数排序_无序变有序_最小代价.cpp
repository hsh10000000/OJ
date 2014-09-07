#include <iostream>
#include <limits>
using namespace std;
//计数排序，计算某个元素的正确位置,
//使用map进行映射也可
int * countSort(int *data,int n)//计数排序
{
	int mini=numeric_limits<int>::max();
	int maxi=numeric_limits<int>::min();
	for(int i=1;i<=n;++i){
		if(data[i]<mini){
			mini=data[i];
		}
		if(data[i]>maxi){
			maxi=data[i];
		}
	}
	int *position=new int[maxi-mini+1];
	for(int i=0;i<maxi-mini+1;++i){
		position[i]=0;
	}
	for(int i=1;i<=n;++i){
		position[data[i]-mini]+=1;
	}
	for(int i=1;i<maxi-mini+1;++i){
		position[i]+=position[i-1];
	}
	/*for(int i=0;i<maxi-mini+1;++i){
		cout<<position[i]<<" ";
	}
	cout<<endl;*/
	return position;
}

int main()
{
	int n;
	cin>>n;
	int *arr=new int[n+1];
	bool *flag=new bool[n+1];
	int gmin=numeric_limits<int>::max();
	for(int i=1;i<=n;++i){
		cin>>arr[i];
		flag[i]=false;
		if(arr[i]<gmin){
			gmin=arr[i];//全局最小
		}
	}
	int *position=countSort(arr,n);
	int pos=1,next=1;
	int sum=0,len=0;
	int lsum=0;
	int lmin=numeric_limits<int>::max();
	int s1,s2;
	for(int i=1;i<=n;++i){
		if(!flag[pos]){
			flag[pos]=true;
			if(pos==next){
				while(next<=n && flag[next]){
					++next;
				}
			}
			++len;
			lsum+=arr[pos];//循环节内元素之和
			if(arr[pos]<lmin){
				lmin=arr[pos];//循环节内最小值
			}
			pos=position[arr[pos]-gmin];			
		}else{
			if(len>1){
				s1=lsum+(len-2)*lmin;
				s2=lsum+(len+1)*gmin+lmin;
				sum+=min(s1,s2);
			}
			--i;
			len=0;
			lmin=numeric_limits<int>::max();
			lsum=0;
			pos=next;
		}
	}
	if(len>1){
		s1=lsum+(len-2)*lmin;
		s2=lsum+(len+1)*gmin+lmin;
		sum+=min(s1,s2);
	}
	cout<<sum<<endl;
	delete []arr;
	delete []flag;
	delete []position;
	return 0;
}
