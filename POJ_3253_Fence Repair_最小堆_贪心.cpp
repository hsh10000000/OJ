#include <iostream>
#include <cstdlib>
using namespace std;
#define LL long long
void min_heap(LL *data,int pos,int heap_size)//维护最小堆
{
	int l=2*pos+1;
	int r=2*pos+2;
	int smallest=pos;

	if(l<heap_size && data[smallest]>data[l]){
		smallest=l;
	}
	if(r<heap_size && data[smallest]>data[r]){
		smallest=r;
	}
	if(smallest !=pos){
		LL tmp=data[pos];
		data[pos]=data[smallest];
		data[smallest]=tmp;
		min_heap(data,smallest,heap_size);
	}

}
void build_heap(LL *data,int n)//建立最小堆
{
	for(int i=n/2-1;i>=0;--i){
		min_heap(data,i,n);
	}
}

LL extract_min(LL *data,int &heap_size)//获取最小值
{
	LL min=data[0];
	data[0]=data[heap_size-1];
	--heap_size;
	min_heap(data,0,heap_size);
	return min;
}

void increase_key(LL *data,int heap_size)
{
	int i=heap_size-1;
	LL tmp=data[i];
	while(i-1>=0 && tmp<data[(i-1)/2]){
		data[i]=data[(i-1)/2];
		i=(i-1)/2;
	}
	data[i]=tmp;
}

void insert(LL *data,LL key,int &heap_size)
{
	++heap_size;
	data[heap_size-1]=key;
	increase_key(data,heap_size);	
}

LL calculate(LL *data,int n)
{
	build_heap(data,n);
	int heap_size=n;
	LL min1=0,min2=0;
	LL sum=0;
	LL cal=0;
	while(heap_size>1){
		min1=extract_min(data,heap_size);
		min2=extract_min(data,heap_size);
		sum=min2+min1;
		cal+=sum;
		insert(data,sum,heap_size);
	}
	return cal;
}



int main()
{
	int n;
	while(cin>>n){
		LL *data=new LL[n];
		for(int i=0;i<n;++i){
			cin>>data[i];
		}
		cout<<calculate(data,n)<<endl;
		delete [] data;
	}
}
