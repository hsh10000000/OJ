#include <iostream>
using namespace std;

int find_set(int *f,int no)//查找学生no的代表信仰，并进行路径压缩
{
	if(f[no]!=no){//初始时每个学生的信仰不同，设其为自身代表其信仰
		f[no]=find_set(f,f[no]);//递归的进行路径压缩
	}
	return f[no];
}

void union_set(int *f,int x,int y,int& sum)//学生x和y
{
	int f1=find_set(f,x);
	int f2=find_set(f,y);
	if(f1!=f2){//合并一对学生则将信仰个数减少1
		f[f1]=f2;
		--sum;
	}
}

void make_set(int *f,int no){//初始化结点集合
	f[no]=no;
}

int main()
{
	int n,m;
	int *f;
	int sum;
	int index=0;
	while(cin>>n>>m &&n!=0 &&m!=0){
		sum=n;//信仰的总数，初始为学生总数
		f=new int[n];
		for(int i=0;i<n;++i){
			make_set(f,i);
		}		
		for(int i=0;i<m;++i){
			int p1,p2;
			cin>>p1>>p2;
			union_set(f,p1-1,p2-1,sum);
		}
		cout<<"Case "<<++index<<": "<<sum<<endl;
		delete [] f;
	}
	return 0;
}
