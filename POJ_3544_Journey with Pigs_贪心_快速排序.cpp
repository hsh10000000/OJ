#include <iostream>
#include <cstdlib>
using namespace std;
#define LL long long

typedef struct node{
	LL value;
	int pos;
}node,pig,profit;


int compare(const void *a,const void *b)
{
	if(((node *)a)->value > ((node *)b)->value)
		return 1;
	return -1;
}

int main()
{
	int n;
	LL t;
	while(cin>>n>>t){
		pig *pi=new pig[n];
		LL *dis=new LL[n];
		LL *price=new LL[n];
		profit *pro=new profit[n];
		int *result=new int[n];
		for(int i=0;i<n;++i){
			cin>>pi[i].value;
			pi[i].pos=i;
		}
		for(int i=0;i<n;++i){
			cin>>dis[i];
		}
		for(int i=0;i<n;++i){
			cin>>price[i];
		}
		for(int i=0;i<n;++i){
			pro[i].value=price[i]-t*dis[i];
			pro[i].pos=i;
		}
		qsort(pi,n,sizeof(pig),compare);
		qsort(pro,n,sizeof(profit),compare);

		for(int i=0;i<n;++i){
			result[pro[i].pos]=pi[i].pos;
		}
		for(int i=0;i<n-1;++i){
			cout<<result[i]+1<<" ";
		}
		cout<<result[n-1]+1;
		cout<<endl;
		delete []pi;
		delete []dis;
		delete []price;
		delete []pro;
		delete [] result;
	}
}
