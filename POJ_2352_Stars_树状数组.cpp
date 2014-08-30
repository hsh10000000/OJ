#include <iostream>
using namespace std;
#define num 32006
int tree[num];
int level[num];

void update(int idx)
{
	while(idx<=num){
		tree[idx]++;
		idx+=(idx & (-idx));
	}
}

int read(int idx)
{
	int sum=0;
	while(idx>0){
		sum+=tree[idx];
		idx-=(idx & (-idx));
	}
	return sum;
}

int main()
{
	int n;
	cin>>n;
	int x,y;
	::memset(tree,0,sizeof(int)*num);
	::memset(level,0,sizeof(int)*num);
	for(int i=0;i<n;++i){
		cin>>x>>y;
		++x;
		int k=read(x);
		level[k]++;
		update(x);
	}
	for(int i=0;i<n;++i){
		cout<<level[i]<<endl;
	}
	return 0;
}
