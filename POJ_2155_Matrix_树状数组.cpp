#include <iostream>
using namespace std;

void change(int **mat,int x,int y,int n)
{
	for(int i=x;i<=n;i+=(i & (-i))){
		for(int j=y;j<=n;j+=(j & (-j))){
			mat[i][j]++;
		}
	}
}

int get(int **mat,int x,int y)
{
	int sum=0;
	for (int i=x;i>0;i-=(i & (-i))){
		for(int j=y;j>0;j-=(j & (-j))){
			sum+=mat[i][j];
		}
	}
	return sum%=2;
}

int main()
{
	int c;	
	int n,t;
	int **mat;
	cin>>c;
	for(int k=0;k<c;++k){
		cin>>n>>t;
		mat=new int *[n+1];
		for(int i=0;i<n+1;++i){
			mat[i]=new int [n+1];
			for(int j=0;j<n+1;++j){
				mat[i][j]=0;
			}
		}
		char ch;
		int x1,y1,x2,y2;
		for(int i=0;i<t;++i){
			cin>>ch;
			if('C'==ch){
				cin>>x1>>y1>>x2>>y2;	
				change(mat,x1,y1,n);
				change(mat,x2+1,y2+1,n);				
				change(mat,x2+1,y1,n);
				change(mat,x1,y2+1,n);
			}else{
				cin>>x1>>y1;
				cout<<get(mat,x1,y1)<<endl;
			}
		}

		for(int i=0;i<=n;++i){
			delete[]mat[i];
		}
		delete[]mat;
		cout<<endl;
	}	
	return 0;
}
