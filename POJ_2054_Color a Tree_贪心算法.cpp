#include <iostream>
using namespace std;

typedef struct ColorTree{
	int weight;//该结点权重
	int parent;//该结点父亲结点
	int sum;//收缩后结点的总和
	int count;//收缩后结点包含结点的个数
	int pre;//收缩链表的第一个结点
	int next;//收缩链表的尾结点
	bool used;//记录记得是否已经被处理过
}ColorTree,*pColorTree;

void init(pColorTree * &ct,int n,int r)//初始化结点信息
{
	for(int i=0;i<n;++i){
		cin>>ct[i]->weight;
		ct[i]->parent=-1;
		ct[i]->sum=ct[i]->weight;
		ct[i]->count=1;
		ct[i]->pre=-1;
		ct[i]->next=-1;
		ct[i]->used=false;
	}
	ct[r-1]->used=true;
	int p,c;
	for(int i=0;i<n-1;++i){
		cin>>p>>c;
		ct[c-1]->parent=p-1;//结点c的父节点是p
	}
}

int find_max(pColorTree * &ct,int n)
{
	int index=-1;
	double maxval=-1;
	double tmp;
	for(int i=0;i<n;++i){
		tmp=1.0*ct[i]->sum/ct[i]->count;
		if(!ct[i]->used && tmp>maxval){
			maxval=tmp;
			index=i;
		}
	}
	return index;
}

int Color_a_Tree(pColorTree * &ct,int n,int r)//poj_2054 color a tree
{
	int index;
	for(int i=0;i<n-1;++i){
		index=find_max(ct,n);//返回权重值最大的结点
		ct[index]->used=true;//将该结点标记
		int par;
		for(par=ct[index]->parent;ct[par]->pre!=-1;par=ct[par]->pre);
		ct[par]->sum+=ct[index]->sum;
		ct[par]->count+=ct[index]->count;
		//建立收缩表
		for(par=ct[index]->parent;ct[par]->next!=-1;par=ct[par]->next); 
		ct[index]->pre=par;
		ct[par]->next=index;
	}	
	int ans=0;
	r=r-1;
	for(int i=0;i<n;++i){
		ans+=ct[r]->weight*(i+1);
		r=ct[r]->next;
	}
	return ans;
}

int main()
{
	int n,r;	
	while(cin>>n>>r){
		if(n<1 && r<1){
			break;
		}
		pColorTree *ct=new pColorTree[n];
		for(int i=0;i<n;++i){
			ct[i]=new ColorTree;
		}
		init(ct,n,r);//初始化创建结点，以及创建树		
		cout<<Color_a_Tree(ct,n,r)<<endl;
		for(int i=0;i<n;++i){
			delete [] ct[i];
		}
		delete [] ct;
	}
	return 0;
}
