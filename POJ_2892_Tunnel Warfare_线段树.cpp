#include <iostream>
#include <stack>
using namespace std;

#define  tt 50002
#define  L(x) (x)<<1
#define  R(x) ((x)<<1)|1
struct interval_tree{
	int low,high;
	int Llen,Rlen;
}it[tt*4];

void update_data(int id)
{
	it[id].Llen=it[L(id)].Llen;
	it[id].Rlen=it[R(id)].Rlen;
	if(it[L(id)].Llen==it[L(id)].high-it[L(id)].low+1){
		it[id].Llen+=it[R(id)].Llen;
	}
	if(it[R(id)].Rlen==it[R(id)].high-it[R(id)].low+1){
		it[id].Rlen+=it[L(id)].Rlen;
	}
}

void create(int id,int low,int high)
{
	it[id].low=low,it[id].high=high;
	if(low==high){
		it[id].Llen=it[id].Rlen=1;
		return;
	}

	int mid=(low+high)>>1;
	create(L(id),low,mid);
	create(R(id),mid+1,high);
	update_data(id);	
}

void update(int id,int node,int flag)
{
	if(it[id].low==it[id].high){
		it[id].Llen=it[id].Rlen=flag;
		return;
	}
	int mid=(it[id].low+it[id].high)>>1;
	if(node<=mid){
		update(L(id),node,flag);
	}else{
		update(R(id),node,flag);
	}
	update_data(id);
}
int query(int id,int node)
{
	if(it[id].low==it[id].high){
		return it[id].Llen;
	}
	int mid=(it[id].low+it[id].high)>>1;
	if(node<=mid){
		if(it[L(id)].high-it[L(id)].Rlen+1<=node){
			return it[L(id)].Rlen+it[R(id)].Llen;
		}else{
			return query(L(id),node);
		}
	}else{
		if(it[R(id)].low+it[R(id)].Llen-1>=node){
			return it[L(id)].Rlen+it[R(id)].Llen;
		}else{
			return query(R(id),node);
		}
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	create(1,1,n);
	char c;int node;	
	stack<int> sta;
	for(int i=0;i<m;++i){
		scanf("\n%c",&c);
		if('D'==c){
			scanf("%d",&node);
			update(1,node,0);
			sta.push(node);
		}else if('Q'==c){
			scanf("%d",&node);
			printf("%d\n",query(1,node));
		}else{
			if(!sta.empty()){
				update(1,sta.top(),1);
				sta.pop();	
			}
		}
	}	
	return 0;
}
