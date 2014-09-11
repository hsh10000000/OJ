#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct node{//孩子兄弟链表法
	int value;
	node *parent;
	node *child;
	node *sibling;
	bool visited;
}node,*pNode;

vector<int>query[901];

void create(pNode*&pn,int root,vector<int>&vec)//创建二叉树
{
	if(!pn[root]){
		pn[root]=new node;
		pn[root]->child=NULL;
		pn[root]->parent=pn[root];
		pn[root]->sibling=NULL;
		pn[root]->value=root+1;
		pn[root]->visited=false;
	}
	int len=vec.size();
	for(int i=0;i<len;++i){
		if(!pn[vec[i]-1]){
			pn[vec[i]-1]=new node;
			pn[vec[i]-1]->child=NULL;			
			pn[vec[i]-1]->sibling=NULL;
			pn[vec[i]-1]->value=vec[i];
			pn[vec[i]-1]->visited=false;
		}
		pn[vec[i]-1]->parent=pn[root];
		if(!(pn[root]->child)){
			pn[root]->child=pn[vec[i]-1];
		}else{
			pn[vec[i]-1]->sibling=pn[root]->child;
			pn[root]->child=pn[vec[i]-1];
		}
	}
}

pNode find_set(pNode &px)//路径压缩
{
	if(px!=px->parent){
		px->parent=find_set(px->parent);
	}
	return px->parent;
}

void union_elem(pNode &px,pNode &py)//合并
{
	pNode p1=find_set(px);
	pNode p2=find_set(py);
	if(p1!=p2){
		p2->parent=p1;
	}
}

void least_common_ancestor(pNode *&pn,int idx,int *&num_re)
{
	pNode ptmp=pn[idx]->child;
	pn[idx]->parent=pn[idx];
	while(ptmp){
		least_common_ancestor(pn,ptmp->value-1,num_re);
		union_elem(pn[idx],ptmp);
		ptmp=ptmp->sibling;
	}
	pn[idx]->visited=true;
	int len=query[idx].size();
	for(int i=0;i<len;++i){
		if(pn[query[idx][i]]->visited){
			++num_re[find_set(pn[query[idx][i]])->value-1];
		}
	}
}

int main()
{
	int n;
	pNode *pn;
	vector<int>vec;
	while(scanf("%d",&n)!=EOF){
		pn=new pNode[n];
		for(int i=0;i<n;++i){
			pn[i]=NULL;
			query[i].clear();
		}
		int root,num,val;
		for(int t=0;t<n;++t){			
			scanf("%d:(%d)",&root,&num);
			//swap(vector<int>(),vec);
			vec.clear();
			for(int i=0;i<num;++i){
				scanf("%d",&val);
				vec.push_back(val);
			}
			create(pn,root-1,vec);
		}
		int m,num1,num2;
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("\n(%d %d)",&num1,&num2);
			query[num1-1].push_back(num2-1);
			query[num2-1].push_back(num1-1);			
		}
		int *num_re=new int[n];
		for(int i=0;i<n;++i){
			num_re[i]=0;
		}
		for(int i=0;i<n;++i){
			if(pn[i]->parent==pn[i]){
				least_common_ancestor(pn,i,num_re);
				break;
			}
		}
		for(int i=0;i<n;++i){
			if(num_re[i]){
				printf("%d:%d\n",i+1,num_re[i]);
			}
		}
		for(int i=0;i<n;++i){
			delete[]pn[i];
		}
		delete[]pn;
		delete[]num_re;
	}
	return 0;
}
