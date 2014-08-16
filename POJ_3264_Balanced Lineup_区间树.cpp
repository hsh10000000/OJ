#include <iostream>
#include <cstdio>
using namespace std;

typedef struct interval_tree{
	int low,high;
	int min,max;
	interval_tree *left,*right;
}interval_tree,*pInterval_tree;

void create(pInterval_tree &pit,int *&height,int low,int high,int &index)//创建区间树
{
	pit=new interval_tree;
	pit->low=low,pit->high=high;
	pit->left=NULL,pit->right=NULL;
	if(low!=high){
		create(pit->left,height,low,(low+high)>>1,index);
		create(pit->right,height,((low+high)>>1)+1,high,index);
		pit->min=pit->left->min > pit->right->min ? pit->right->min : pit->left->min;
		pit->max=pit->left->max > pit->right->max ? pit->left->max : pit->right->max;
	}else{
		pit->min=height[index],pit->max=height[index];
		++index;
	}	
}

void query(pInterval_tree &pit,int low,int high,int &maxi,int &mini)//查询区间树
{
	if(pit->low<=high && pit->high>=low){//pit所表示的区间和[low,high]区间相交
		int max1,min1,max2,min2;
		if(pit->low==low && pit->high==high){
			maxi=pit->max,mini=pit->min;
		}else{
			if(high<=((pit->low+pit->high)>>1)){
				query(pit->left,low,high,maxi,mini);
			}else if(low>=((pit->low+pit->high)>>1)+1){
				query(pit->right,low,high,maxi,mini);
			}else{
				query(pit->left,low,(pit->low+pit->high)>>1,maxi,mini);
				max1=maxi,min1=mini;
				query(pit->right,((pit->low+pit->high)>>1)+1,high,maxi,mini);
				max2=maxi,min2=mini;
				maxi=max(max1,max2);
				mini=min(min1,min2);
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
	//cin>>n>>q;
	scanf("%d%d",&n,&q);
	int *height=new int[n];
	for(int i=0;i<n;++i){
		//cin>>height[i];
		scanf("%d",&height[i]);
	}
	pInterval_tree pit=NULL;
	int index=0;
	create(pit,height,1,n,index);
	int max,min;
	int low,high;
	for(int i=0;i<q;++i){
		//cin>>low>>high;
		scanf("%d%d",&low,&high);
		query(pit,low,high,max,min);
		printf("%d\n",max-min);
		//cout<<max-min<<endl;
	}
	delete[]height;
	del(pit,1,n);
	return 0;
}
