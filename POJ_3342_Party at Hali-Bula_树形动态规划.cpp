#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef struct node{
	string name;//结点名字
	node *child;//孩子结点
	node *sibling;//兄弟结点
	node *parent;//父亲结点
	int co[2];//以该结点为根结点时的最多人数
	bool flag[2];//标记该结点是否具有唯一方案
}node,*pNode;

pNode search(string &str,map<string,pNode>&ma)//查找指定结点
{
	pNode pr=NULL;
	map<string,pNode>::iterator iter;
	for(iter=ma.begin();iter!=ma.end();++iter){
		if(str==iter->first){
			pr=ma[str];
			break;
		}
	}
	return pr;
}

void make_set(string &strBoss,string &strEmp,map<string,pNode>&ma)//孩子兄弟链表法
{
	node *no;
	pNode pp=search(strBoss,ma);
	if(!pp){//Boss结点为空
		no=new node;
		no->child=NULL;
		no->sibling=NULL;
		no->flag[0]=no->flag[1]=true;//初始将所有结点都标记为具有唯一方案
		no->co[0]=0,no->co[1]=1;//co[0]表示不选择该结点时的最多人数，co[1]则相反
		no->name=strBoss;
		ma[strBoss]=no;
	}
	if(""!=strEmp){
		pNode pc=search(strEmp,ma);
		if(!pc){
			no=new node;
			no->child=NULL;
			no->sibling=NULL;
			no->flag[0]=no->flag[1]=true;//初始将所有结点都标记为具有唯一方案
			no->co[0]=0,no->co[1]=1;//co[0]表示不选择该结点时的最多人数，co[1]则相反
			no->name=strEmp;
			ma[strEmp]=no;
		}
		ma[strEmp]->parent=ma[strBoss];
		ma[strEmp]->sibling=ma[strBoss]->child;
		ma[strBoss]->child=ma[strEmp];
	}
}

void release(pNode &bb)//释放结点
{
	if(bb){
		pNode pt=bb->child;
		while(pt){
			pNode ptmp =pt->sibling;
			release(pt);
			pt=ptmp;
		}
		delete bb;
	}	
}

void dp_tree(pNode &bb)//树形DP,动态规划
{
	if(bb){
		pNode pt=bb->child;
		while(pt){
			pNode ptmp =pt->sibling;
			dp_tree(pt);
			bb->co[0]+=max(pt->co[0],pt->co[1]);
			bb->co[1]+=pt->co[0];
			
			if((pt->co[0]>pt->co[1] && !pt->flag[0])||
			   (pt->co[1]>pt->co[0] && !pt->flag[1])||
			   (pt->co[0]==pt->co[1])){
				bb->flag[0]=false;
			}
			if(!pt->flag[0]){
				bb->flag[1]=false;
			}	
			pt=ptmp;
		}
	}
}

int main()
{
	int n;
	string strBoss,strEmp;
	node *bb;
	map<string,pNode>ma;
	while(cin>>n,n){
		ma.clear();
		strEmp="";
		cin>>strBoss;
		make_set(strBoss,strEmp,ma);
		bb=ma[strBoss];
		for(int i=0;i<n-1;++i){
			cin>>strEmp>>strBoss;
			make_set(strBoss,strEmp,ma);
		}
		dp_tree(bb);
		int index=0;
		if(bb->co[0]<bb->co[1]){
			index=1;
		}
		cout<<bb->co[index]<<" ";
		if(bb->co[0]!=bb->co[1]){			
			if(bb->flag[index]){
				cout<<"Yes"<<endl;
			}else{
				cout<<"No"<<endl;
			}
		}else{
			cout<<"No"<<endl;
		}
		release(bb);
	}
	return 0;
}
