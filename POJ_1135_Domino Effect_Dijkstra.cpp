#include <iostream>
#include <limits>
#include <iomanip> 
using namespace std;

int extract_min(int *d,bool *visited,int n)
{
	int mini=numeric_limits<int>::max();
	int index=-1;
	for(int i=1;i<n;++i){
		if(!visited[i] && d[i]<mini){
			mini=d[i];
			index=i;
		}
	}
	return index;
}

void relax(int **mat,int *d,bool *visited,int index,int n)//邻接结点松弛操作
{
	for(int i=1;i<n;++i){
		if(i!=index && !visited[i] && mat[index][i]!=numeric_limits<int>::max()){
			if(d[index]+mat[index][i]<d[i]){
				d[i]=d[index]+mat[index][i];
			}
		}
	}	
}
void print(int **mat,int* d,int n,int m,int num)
{
	double maxi=0;
	int p1=1,p2=1;
	double tmp;
	for(int i=0;i<n;++i){
		for(int j=1;j<n;++j){
			if(i!=j && mat[i][j]!=numeric_limits<int>::max()){
				tmp=1.0*(d[i]+d[j]+mat[i][j])/2;
				if(tmp>maxi){
					maxi=tmp;
					p1=i+1,p2=j+1;
				}
			}
		}
	}
	cout<<"System #"<<num<<endl;
	cout << std::fixed<< std::setprecision(1);
	cout<<"The last domino falls after "<<maxi<<" seconds, ";
	if(d[p1-1]==maxi){
		cout<<"at key domino "<<p1<<"."<<endl;
	}else if(d[p2-1]==maxi){
		cout<<"at key domino "<<p2<<"."<<endl;
	}else{
		cout<<"between key dominoes ";
		if(p1>p2){
			int tmp=p1;
			p1=p2;
			p2=tmp;
		}
		cout<<p1<<" and "<<p2<<"."<<endl;
	}
	cout<<endl;
}
void dijkstra(int **mat,int *d,bool *visited,int n)//单源最短路径优先
{
	int left=n;
	int index;
	while(--left){
		index=extract_min(d,visited,n);
		relax(mat,d,visited,index,n);
		visited[index]=true;
	}	
}

int main()
{
	int n,m;
	int a,b,l;
	int **mat;//邻接矩阵
	int *d;
	bool *visited;
	int num=0;
	while(cin>>n>>m){		
		if(n==0 && m==0){
			break;
		}
		mat=new int *[n];
		for(int i=0;i<n;++i){
			mat[i]=new int [n];
			for(int j=0;j<n;++j){
				mat[i][j]=numeric_limits<int>::max();
			}
			mat[i][i]=0;
		}
		for(int i=0;i<m;++i){
			cin>>a>>b>>l;
			mat[a-1][b-1]=l;
			mat[b-1][a-1]=l;
		}

		d=new int[n];
		visited=new bool[n];
		for(int i=0;i<n;++i){
			d[i]=mat[0][i];
			visited[i]=false;
		}
		visited[0]=true;//第一个结点是起始结点
		dijkstra(mat,d,visited,n);
		++num;
		print(mat,d,n,m,num);
		for(int i=0;i<n;++i){
			delete []mat[i];
		}
		delete []mat;
		delete []d;
		delete []visited;
	}
	return 0;
}
