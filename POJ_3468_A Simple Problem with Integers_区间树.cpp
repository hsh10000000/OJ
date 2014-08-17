#include <iostream>
#include <cstdio>
using namespace std;

#define LL long long

typedef struct interval_tree{
	int low,high;
	LL sum;//存储当前子树结点值之和
	LL mark;//当前区间标记
	interval_tree *left,*right;
}interval_tree,*pInterval_tree;

void create(pInterval_tree &pit,LL *&height,int low,int high,int &index)//创建区间树
{
	pit=new interval_tree;
	pit->low=low,pit->high=high;
	pit->left=NULL,pit->right=NULL;
	pit->mark=0;//标记初始化为0
	if(low!=high){
		create(pit->left,height,low,(low+high)>>1,index);
		create(pit->right,height,((low+high)>>1)+1,high,index);
		pit->sum=pit->left->sum+pit->right->sum;		
	}else{
		pit->sum=height[index];
		++index;
	}	
}

void modify(pInterval_tree &pit,int low,int high,int mark)//修改结点值
{
	if(pit->low<=high && pit->high>=low){
		if(pit->low==low && pit->high==high){
			pit->sum+=(pit->high-pit->low+1)*mark;
			pit->mark+=mark;
		}else{
			if(pit->mark){
				pit->left->mark+=pit->mark;
				pit->left->sum+=(pit->left->high-pit->left->low+1)*pit->mark;
				pit->right->mark+=pit->mark;
				pit->right->sum+=(pit->right->high-pit->right->low+1)*pit->mark;
				pit->mark=0;
			}
			if(high<=((pit->low+pit->high)>>1)){
				modify(pit->left,low,high,mark);
			}else if(low>=((pit->low+pit->high)>>1)+1){
				modify(pit->right,low,high,mark);
			}else{
				modify(pit->left,low,(pit->low+pit->high)>>1,mark);
				modify(pit->right,((pit->low+pit->high)>>1)+1,high,mark);
			}
			pit->sum=pit->left->sum+pit->right->sum;
		}
	}	
}

void query(pInterval_tree &pit,int low,int high,LL &sum)//查询区间树
{ 
	if(pit->low<=high && pit->high>=low){//pit所表示的区间和[low,high]区间相交
		if(pit->low==low && pit->high==high){
			sum+=pit->sum;
		}else{
			if(pit->mark){
				pit->left->mark+=pit->mark;
				pit->left->sum+=(pit->left->high-pit->left->low+1)*pit->mark;
				pit->right->mark+=pit->mark;
				pit->right->sum+=(pit->right->high-pit->right->low+1)*pit->mark;
				pit->mark=0;
			}
			if(high<=((pit->low+pit->high)>>1)){
				query(pit->left,low,high,sum);
			}else if(low>=((pit->low+pit->high)>>1)+1){
				query(pit->right,low,high,sum);
			}else{
				query(pit->left,low,(pit->low+pit->high)>>1,sum);
				query(pit->right,((pit->low+pit->high)>>1)+1,high,sum);
			}
		}
	}
}

void del(pInterval_tree &pit,int low,int high)
{
	if(low!=high){
		del(pit->left,low,(low+high)>>1);
		del(pit->right,((low+high)>>1)+1,high);
	}else{
		delete pit;
	}
}

int main()
{
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF){
		LL *height=new LL[n];
		for(int i=0;i<n;++i){
			scanf("%I64d",&height[i]);
		}
		pInterval_tree pit=NULL;
		int index=0;
		create(pit,height,1,n,index);	
		int low,high,mark;
		char op;
		for(int i=0;i<q;++i){
			scanf("\n%c%d%d",&op,&low,&high);
			if('C'==op){
				scanf("%d",&mark);
				modify(pit,low,high,mark);
			}else{
				LL sum=0;
				query(pit,low,high,sum);
				printf("%I64d\n",sum);
			}
		}
		delete[]height;
		del(pit,1,n);
	}
	return 0;
}
