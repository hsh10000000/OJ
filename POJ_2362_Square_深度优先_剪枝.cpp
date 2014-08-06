#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b)//
{
	return a>b;
}

bool dfs(int *data,bool *visit,int sum,int side,int index,int len,int n)//poj2362,深度优先搜索
{//index作为下一次深度优先的其实索引，因为index前的元素在上一次深度优先的时候已经搜索过，因为下次深度优先将不再搜索
	if(side==2 && sum==len){
		return true;
	}
	if(sum==len){
		sum=0;++side;index=0;
	}
	for(int i=index;i<n;++i){		
		if(visit[i] || sum+data[i]>len){//该结点已经被访问过或者其和大于边长
			continue;
		}
		visit[i]=true;
		if(dfs(data,visit,sum+data[i],side,i+1,len,n)){
			return true;
		}
		visit[i]=false;		
		if(sum==0||sum+data[i]==len){//剪枝,sum==0表示当前这个元素无法与后面的元素组合成一根棒，
			break;                   //sum+data[i]==len表示当前元素可以和后面的元素组合成一根棒， 
		}                            //但是，当前元素之后的元素无法再组合成一根棒，这两种情况都需要提前终止 
		while(i+1<n && data[i+1]==data[i]){
			++i;
		}//但是，当前元素之后的元素无法再组合成一根棒，这两种情况都需要提前终止 	
	}
	return false;
}

int main()
{
	int n;
	int *data;
	int sum=0;
	bool *visit;
	cin>>n;
	int m;
	int len;
	for(int i=0;i<n;++i){
		cin>>m;
		data=new int[m];
		visit=new bool[m];
		sum=0;
		for(int i=0;i<m;++i){
			cin>>data[i];
			sum+=data[i];
		}
		sort(data,data+m,compare);
		if(sum%4==0 && (len=sum/4)>=data[0]){					
			memset(visit,false,sizeof(bool)*m);
			if(dfs(data,visit,0,0,0,len,m)){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}
		}else{
			cout<<"no"<<endl;
		}		
		delete [] data;
		delete [] visit;
	}
	return 0;
}
