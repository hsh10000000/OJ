#include <iostream>
#include <string>
using namespace std;

int find_set(int *f,int x)//带路径压缩
{
	if(f[x]!=x){
		f[x]=find_set(f,f[x]);
	}
	return f[x];
}

void union_set(int *f,int a,int b)//集合合并
{
	int f1=find_set(f,a);
	int f2=find_set(f,b);
	if(f1!=f2){
		f[f1]=f2;
	}
}

bool check(int *f,bool *good,int nx,int ny)
{
	if(good[nx] &&good[ny]){
		if(find_set(f,nx)==find_set(f,ny)){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
	
}

int main()
{
	int N,d;
	cin>>N>>d;
	int *corX=new int[N];
	int *corY=new int[N];
	bool *good=new bool[N];
	int *f=new int[N];
	for(int i=0;i<N;++i){
		cin>>corX[i]>>corY[i];
		good[i]=false;
		f[i]=i;
	}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			int disX=corX[i]-corX[j];
			int disY=corY[i]-corY[j];
			int dis=disX*disX+disY*disY;
			if(dis<=d*d){
				union_set(f,i,j);
			}
		}
	}
	string str;

	while (cin>>str)
	{
		if(str=="O"){
			int node;
			cin>>node;
			good[node]=true;
		}else if(str=="S"){
			int nx,ny;
			cin>>nx>>ny;
			if(check(f,good,nx-1,ny-1)){
				cout<<"SUCCESS"<<endl;
			}else{
				cout<<"FAIL"<<endl;
			}
		}
	}

	delete[]corX;
	delete[]corY;
	delete[]good;
	delete[]f;
	return 0;
}
