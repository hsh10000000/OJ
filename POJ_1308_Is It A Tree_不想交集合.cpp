#include <iostream>
#include <map>
using namespace std;

int find_set(map<int ,int > &map_tree,int x)//查找祖父结点，并进行路径压缩
{
	if(map_tree[x]!=x){
		map_tree[x]=find_set(map_tree,map_tree[x]);
	}
	return map_tree[x];
}

bool union_set(map<int ,int > &map_tree,int x,int y)
{
	int f1=find_set(map_tree,x);
	int f2=find_set(map_tree,y);
	if(f2!=y){//y要成为其他结点的孩子，首先它不能是另外一些结点的孩子，它必须是自己的孩子，否则它有两个父亲结点
		return false;
	}
	if(f1==f2){//如果x和y本身具有相同的祖父结点，则x和y不能在合并，否则将形成环
		return false;
	}else{
		map_tree[f2]=f1;
	}
	return true;
}

int main()
{
	map<int ,int >map_tree;
	int x,y;
	int time=0;	
	bool flag=true;
	int count=0;
	while(cin>>x>>y){			
		if(x<=-1 && y<=-1){//输入负数表示结束
			break;;
		}

		if(x==0 && y==0){
			++time;
			for(map<int ,int >::iterator iter=map_tree.begin();iter!=map_tree.end();++iter){
				if(iter->first==iter->second){
					++count;//计算根结点的个数
				}
			}
			if(flag && count<2){
				cout<<"Case "<<time<<" is a tree."<<endl;
			}else{
				cout<<"Case "<<time<<" is not a tree."<<endl;
			}
			map<int,int>().swap(map_tree);
			map_tree.clear();
			count=0;
			flag=true;
			continue;
		}
		if(map_tree.count(x)<=0)//判断map中是否已经存在该结点
			map_tree[x]=x;
		if(map_tree.count(y)<=0)
			map_tree[y]=y;
		flag =flag && union_set(map_tree,x,y);	
	}
	return 0;
}
