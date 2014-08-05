#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void *a,const void *b)//
{
	return *((int *)b)-*((int *)a);
}

bool dfs(int *data,bool *visit,int sum,int index,int len,int n)//poj1011,深度优先搜索
{
	if(index==n && sum==len){
		return true;
	}
	if(sum==len){
		sum=0;
	}
	for(int i=0;i<n;++i){
		if(visit[i]){//该结点已经被访问过
			continue;
		}
		if(sum+data[i]>len){//和大于棍棒长度
			continue;
		}
		visit[i]=true;
		if(dfs(data,visit,sum+data[i],index+1,len,n)){
			return true;
		}
		visit[i]=false;
		if(sum==0||sum+data[i]==len){//剪枝,sum==0表示当前这个元素无法与后面的元素组合成一根棒，
			break;                   //sum+data[i]==len表示当前元素可以和后面的元素组合成一根棒， 
		}                            //但是，当前元素之后的元素无法再组合成一根棒，这两种情况都需要提前终止 
	}
	return false;
}


int main()
{
	int n;
	int *data;
	int sum=0;
	bool *visit;
	while(cin>>n,n){
		data=new int[n];
		visit=new bool[n];
		sum=0;
		for(int i=0;i<n;++i){
			cin>>data[i];
			sum+=data[i];
		}
		qsort(data,n,sizeof(int),compare);
		for(int len=data[0];len<=sum;++len){
			if(!(sum % len)){
				memset(visit,false,sizeof(bool)*n);
				if(dfs(data,visit,0,0,len,n)){
					cout<<len<<endl;
					break;
				}
			}
		}
		delete [] data;
		delete [] visit;
	}
	return 0;
}
