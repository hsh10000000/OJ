#include <iostream>
#include <ctime>
using namespace std;

int partition(int *a,int low,int high)
{
	if(low<high){
		int pivot=a[high];
		int p=low-1;
		int tmp;
		for(int i=low;i<high;++i){
			if(a[i]<pivot){
				p++;
				tmp=a[i];
				a[i]=a[p];
				a[p]=tmp;
			}
		}
		tmp=a[p+1];
		a[p+1]=a[high];
		a[high]=tmp;
		return p+1;
	}
	return 0;
}

int random_partition(int *a,int low,int high)
{
	int rnd=rand()%(high-low+1)+low;
	int tmp=a[rnd];
	a[rnd]=a[high];
	a[high]=tmp;
	return partition(a,low,high);
}

int random_select(int *a,int low,int high,int loc)//随机化中位数法
{
	if(low==high){
		return a[low];
	}
	int q=random_partition(a,low,high);
	int k=q-low+1;
	if(k==loc){
		return a[q];
	}else if(k<loc){
		return random_select(a,q+1,high,loc-k);
	}else{
		return random_select(a,low,q-1,loc);
	}
}

void quick_sort(int *a,int low,int high)
{
	if(low<high){
		int index=partition(a,low,high);
		quick_sort(a,low,index-1);
		quick_sort(a,index+1,high);
	}
}

int main()
{
	srand((unsigned)time(NULL));
	int N;
	cin>>N;
	int *data=new int[N];
	for(int i=0;i<N;++i){
		cin>>data[i];
	}
	cin.ignore(3,'\n');
	cin.ignore(3,'\n');
	int k;
	cin>>k;
	int loc;
	for(int i=0;i<k;++i){
		cin>>loc;
		int tmp=random_select(data,0,N-1,loc);
		cout<<tmp<<endl;
	}
	delete [] data;
}
