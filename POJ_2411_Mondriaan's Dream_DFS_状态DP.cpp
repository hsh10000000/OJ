#include <iostream>
using namespace std;
long long sum[2][1<<11];//利用滚动数组节约空间

void dfs(int col,int next,int prev,int t,int w)//深度优先，DP动态规划
{
	if(col==w){
		sum[t%2][next]+=sum[(t+1)%2][prev];
		return;
	}else{
		if(col+1<=w){
			dfs(col+1,(next<<1)|1,prev<<1,t,w);//竖着放置
			dfs(col+1,next<<1,(prev<<1)|1,t,w);//不放置
		}
		if(col+2<=w){
			dfs(col+2,(next<<2)|3,(prev<<2)|3,t,w);//横着放置
		}
	}
}

int main()
{
	int h,w;
	while(cin>>h>>w,h||w){
		if((h*w)%2){
			cout<<0<<endl;
		}else{
			if(h<w){
				h^=w,w^=h,h^=w;
			}
			memset(sum,0,sizeof(sum));
			int t=0;
			sum[t][(1<<w)-1]=1;
			for(int i=0;i<h;++i){
				t=(t+1)%2;
				dfs(0,0,0,t,w);
				memset(sum[(t+1)%2],0,sizeof(sum[0]));
			}
			cout<<sum[t][(1<<w)-1]<<endl;
		}
	}
}
