#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

bool compare(int a,int b)
{
	return a<b;
}

typedef struct interval_tree{
	int low,high;
	bool covered;
	interval_tree *left,*right;
}interval_tree,*pInterval_tree;
typedef struct point{
	int low,high;
}point,*pPoint;

void create(pInterval_tree &pit,int low,int high)//建立线段树
{
	pit=new interval_tree;
	pit->low=low;pit->high=high;
	pit->covered=false;
	pit->left=NULL;pit->right=NULL;
	if(low!=high){
		create(pit->left,low,(low+high)>>1);
		create(pit->right,((low+high)>>1)+1,high);
	}	
}

void modify_query(pInterval_tree &pit,int low,int high,bool &flag)//查询和修改操作
{
	if(!pit->covered){
		if(pit->low==low && pit->high==high){
			pit->covered=true;
			flag=true;
		}else{
			if(high<=((pit->high+pit->low)>>1)){
				modify_query(pit->left,low,high,flag);
			}else if(low>((pit->high+pit->low)>>1)){
				modify_query(pit->right,low,high,flag);
			}else{
				modify_query(pit->left,low,(pit->high+pit->low)>>1,flag);
				modify_query(pit->right,((pit->high+pit->low)>>1)+1,high,flag);
			}
			pit->covered=pit->left->covered && pit->right->covered;	
		}
	}
}

void del(pInterval_tree &pit)
{
	if(pit->low!=pit->high){
		del(pit->left);
		del(pit->right);
	}else{
		delete pit;
	}
}

int main()
{
	int t;
	cin>>t;
	int n;
	pPoint pp;
	int low,high;
	int *data;
	map<int,int>ma;
	pInterval_tree pit;
	for(int k=0;k<t;++k){
		cin>>n;
		pp=new point[n];
		data=new int[n*2];
		int index=0;
		for(int i=0;i<n;++i){
			cin>>low>>high;
			pp[i].low=low;
			pp[i].high=high;
			data[index++]=low;
			data[index++]=high;
		}
		sort(data,data+index,compare);//对数据排序
		ma[data[0]]=0;
		int num=1;
		for(int i=1;i<index;++i){
			if(data[i]!=data[i-1]){
				ma[data[i]]=num++;
			}
		}
		pit=NULL;
		create(pit,0,num-1);
		int ans=0;
		for(int i=n-1;i>=0;--i){
			bool flag=false;
			modify_query(pit,ma[pp[i].low],ma[pp[i].high],flag);
			if(flag){
				++ans;
			}
		}
		cout<<ans<<endl;
		delete[]pp;
		delete[]data;
		del(pit);
		ma.clear();
	}
	return 0;
}
