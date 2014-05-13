#include <iostream>
#include <map>
using namespace std;

int find_set(map<int ,int > &map_tree,int x)
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
	if(f2!=y){
		return false;
	}
	if(f1==f2){
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
					++count;
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
		if(map_tree.count(x)<=0)
			map_tree[x]=x;
		if(map_tree.count(y)<=0)
			map_tree[y]=y;
		flag =flag && union_set(map_tree,x,y);	
	}
	return 0;
}
