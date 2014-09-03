#include <iostream>
using namespace std;

void solve(char **mat,int m,int n)
{
	int round=(min(m,n)-1)/2+1;//计算填充的圈数
	int idx=-1,idy=n+1;
	int c=0;
	for(int t=0;t<round;++t){
		idx=t,idy=n-t;
		for(int j=t;j<idy;++j){
			if(!mat[idx][j]){
				mat[idx][j]='A'+(c++)%26;
			}
		}
		idy=n-1-t,idx=m-t;
		for(int i=t+1;i<idx;++i){
			if(!mat[i][idy]){
				mat[i][idy]='A'+(c++)%26;
			}
		}
		idx=m-1-t,idy=n-1-t;
		for(int j=idy-1;j>=t;--j){
			if(!mat[idx][j]){
				mat[idx][j]='A'+(c++)%26;
			}
		}
		idx=m-2-t;idy=t;
		for(int i=idx;i>t;--i){
			if(!mat[i][idy]){
				mat[i][idy]='A'+(c++)%26;
			}
		}
	}
}

int main()
{
	int m,n;
	cin>>m>>n;
	char **mat=new char *[m];
	for(int i=0;i<m;++i){
		mat[i]=new char [n];
		for(int j=0;j<n;++j){
			mat[i][j]=0;
		}
	}
	solve(mat,m,n);
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			cout<<"   "<<mat[i][j];
		}
		cout<<endl;
	}
	for(int i=0;i<m;++i){
		delete[]mat[i];
	}
	delete[]mat;
	return 0;
}
