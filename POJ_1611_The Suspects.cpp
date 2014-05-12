#include <iostream>
using namespace std;

int find_set(int *par,int x)
{
	if(par[x]!=x){
		par[x]=find_set(par,par[x]);
	}
	return par[x];
}

void union_set(int *par,int x,int y)
{
	int f1=find_set(par,x);
	int f2=find_set(par,y);
	if(f2!=f1){
		par[f2]=f1;
	}
}

int main()
{
	int n,m;
	int *par;
	int gro_num;
	
	while (cin>>n>>m){
		if(m==0 && n==0){
			return 0;
		}
		par=new int[n];
		for(int i=0;i<n;++i){
			par[i]=i;
		}

		for (int i = 0; i < m; i++){
			cin>>gro_num;
			int no1,no2;
			cin>>no1;
			for(int j=0;j<gro_num-1;++j){
				cin>>no2;
				union_set(par,no1,no2);
			}
		}
		int sum=1;
		for(int i=1;i<n;++i){
			if(find_set(par,i)==find_set(par,0)){
				++sum;
			}
		}
		cout<<sum<<endl;
		delete par;
	}
	return 0;
}
