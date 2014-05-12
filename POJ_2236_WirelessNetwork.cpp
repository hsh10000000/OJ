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

void check(int *f,int nx,int ny)
{	
	if(find_set(f,nx)==find_set(f,ny)){
		cout<<"SUCCESS"<<endl;
	}else{
		cout<<"FAIL"<<endl;
	}
}

int main()
{
	int N,d;
	cin>>N>>d;
	int *corX=new int[N];//记录 X坐标值
	int *corY=new int[N];//记录Y坐标值
	bool *good=new bool[N];//记录电脑状态
	int *f=new int[N];//记录父亲结点
	bool **conn=new bool*[N];//记录链接状态
	for(int i=0;i<N;++i){
		conn[i]=new bool [N];
		for(int j=0;j<N;++j){
			conn[i][j]=false;
		}
		conn[i][i]=true;
	}
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
				conn[i][j]=true;
				conn[j][i]=true;
			}
		}
	}

	string str;

	while (cin>>str){
		if(str=="O"){
			int node;
			cin>>node;
			good[node-1]=true;
			for(int i=0;i<N;++i){
				if(conn[i][node-1] && good[i]){
					union_set(f,i,node-1);
				}
			}

		}else{
			int nx,ny;
			cin>>nx>>ny;
			check(f,nx-1,ny-1);
		}
	}

	delete[]corX;
	delete[]corY;
	delete[]good;
	delete[]f;
	for(int i=0;i<N;++i){
		delete[]conn[i];
	}
	delete[]conn;
	return 0;
}
