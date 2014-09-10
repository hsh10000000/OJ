#include <iostream>
using namespace std;

typedef struct node{
	int value;
	bool flag;
	node *parent;
}node,*pNode;

int Nearest_common_ancestors(pNode *&pn,int node1,int node2)
{
	pNode ptmp=pn[node1];
	while(ptmp->parent!=ptmp){
		ptmp->flag=true;
		ptmp=ptmp->parent;
	}
	ptmp->flag=true;
	ptmp=pn[node2];	
	while(!ptmp->flag && ptmp->parent!=ptmp){
		ptmp=ptmp->parent;
	}
	int com=ptmp->value;
	return com;
}

int main()
{
	int t;
	cin>>t;//test case
	int nonum;//node number
	int parent,child;
	for(int k=0;k<t;++k){
		cin>>nonum;	
		pNode *pn=new pNode[nonum];
		for(int i=0;i<nonum;++i){
			pn[i]=new node;
			pn[i]->value=i+1;
			pn[i]->flag=false;
			pn[i]->parent=pn[i];
		}
		for(int i=0;i<nonum-1;++i){
			cin>>parent>>child;
			pn[child-1]->parent=pn[parent-1];
		}
		cin>>parent>>child;
		cout<<Nearest_common_ancestors(pn,parent-1,child-1)<<endl;
		for(int i=0;i<nonum;++i){
			delete[]pn[i];
		}
		delete[]pn;
	}
	return 0;
}
